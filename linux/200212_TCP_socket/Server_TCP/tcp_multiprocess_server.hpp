#pragma once

#include"tcp_socket.hpp"
#include<functional>
#include<signal.h>

typedef std::function<void (const std::string& req, std::string *resp)> Handler;

class tcp_multiprocess_server
{
private:
	tcp_socket _listen_sock;
	std::string _ip;
	uint64_t _port;
public:
	tcp_multiprocess_server(const std::string& ip, uint16_t port):_ip(ip),_port(port)
	{
		signal(SIGCHLD, SIG_IGN);
	}

	void _process_connect(const tcp_socket& new_sock, const std::string& ip, uint16_t port, Handler handler)
	{
		int ret = fork();
		if(ret > 0)
		{
			new_sock._close();
			return;
		}
		else if(ret == 0)
		{
			while(true)
			{
				std::string req;
				if(!new_sock._recv(&req))
				{
					printf("[client %s:%d] disconnected...\n", ip.c_str(), port);
					exit(0);
				}
				std::string resp;
				handler(req, &resp);
				new_sock._send(resp);
				printf("[client %s:%d] req:%s, resp:%s\n", ip.c_str(), port, req.c_str(), resp.c_str());
			}
		}
		else
		{
			perror("fork");
		}
	}

	bool _start(Handler handler)
	{
		CHECK_RET(_listen_sock._socket());
		CHECK_RET(_listen_sock._bind(_ip, _port));
		CHECK_RET(_listen_sock._listen(5));
		while(true)
		{
			tcp_socket new_sock;
			std::string ip;
			uint16_t port = 0;
			if(!_listen_sock._accept(&new_sock, &ip, &port))
			{
				continue;
			}
			printf("[client %s:%d] connect...\n", ip.c_str(), port);
			_process_connect(new_sock, ip, port, handler);
		}
		return true;
	}
};
