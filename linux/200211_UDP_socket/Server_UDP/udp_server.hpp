#pragma once

#include"udp_socket.hpp"
#include<functional>

typedef std::function<void (const std::string&, std::string* resp)> Handler;

class udp_server
{
private:
	udp_socket u_sock;
public:
	udp_server()
	{
		assert(u_sock._socket());
	}

	~udp_server()
	{
		u_sock._close();
	}

	bool _start(const std::string& ip, uint16_t port, Handler handler)
	{
		if(!u_sock._bind(ip, port))
		{
			return false;
		}
		while(true)
		{
			std::string req;
			std::string remote_ip;
			uint16_t remote_port = 0;

			if(!u_sock._recvfrom(&req, &remote_ip, &remote_port))
			{
				continue;
			}

			std::string resp;
			handler(req, &resp);
			u_sock._sendto(resp, remote_ip, remote_port);
			printf("[%s:%d] req:%s, resp:%s\n", remote_ip.c_str(), remote_port, req.c_str(), resp.c_str());
		}
		u_sock._close();
		return true;
	}
};
