#pragma once

#include"udp_socket.hpp"

class udp_client
{
public:
	udp_client(const std::string& ip, uint16_t port):_ip(ip),_port(port)
	{
		assert(u_sock._socket());
	}

	~udp_client()
	{
		u_sock._close();
	}

	bool _recvfrom(std::string* buf)
	{
		return u_sock._recvfrom(buf);
	}

	bool _sendto(const std::string& buf)
	{
		return u_sock._sendto(buf, _ip, _port);
	}
private:
	udp_socket u_sock;
	std::string _ip;
	uint16_t _port;
};
