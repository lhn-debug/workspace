#pragma once

#include"tcp_socket.hpp"
#include<functional>

typedef std::function<void (const std::string& req, std::string *resp)> Handler;

class tcp_server
{
private:
	tcp_socket _listen_sock;
	std::string _ip;
	uint64_t _port;
public:
	tcp_server(const std::string& ip, uint16_t port):_ip(ip),_port(port)
	{}

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

			while(true)
			{
				std::string req;
				bool ret = new_sock._recv(&req);
				if(!ret)
				{
					printf("[client %s:%d] disconnect...\n", ip.c_str(), port);
					new_sock._close();
					break;
				}
				std::string resp;
				handler(req, &resp);
				new_sock._send(resp);
				printf("[%s:%d] req:%s, resp:%s\n", ip.c_str(), port, req.c_str(), resp.c_str());
			}
		}
		return true;
	}
};
