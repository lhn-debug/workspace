#pragma once

#include"tcp_socket.hpp"

class tcp_client
{
private:
	tcp_socket _sock;
	std::string _ip;
	uint16_t _port;
public:
	tcp_client(const std::string& ip, uint16_t port):_ip(ip),_port(port)
	{
		_sock._socket();
	}

	~tcp_client()
	{
		_sock._close();
	}

	bool _connect()
	{
		return _sock._connect(_ip, _port);
	}

	bool _recv(std::string *buf)
	{
		return _sock._recv(buf);
	}

	bool _send(const std::string& buf)
	{
		return _sock._send(buf);
	}
};
