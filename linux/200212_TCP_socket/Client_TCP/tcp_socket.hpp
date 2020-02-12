#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<cassert>
#include<unistd.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

#define CHECK_RET(exp) if(!(exp)){return false;}

class tcp_socket
{
private:
	int _fd;
public:
	tcp_socket():_fd(-1)
	{}

	tcp_socket(int fd):_fd(fd)
	{}

	bool _socket()
	{
		_fd = socket(AF_INET, SOCK_STREAM, 0);
		if(_fd < 0)
		{
			perror("socket");
			return false;
		}
		return true;
	}

	bool _close() const
	{
		close(_fd);
		return true;
	}

	bool _bind(const std::string& ip, uint16_t port) const
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		addr.sin_port = htons(port);

		int ret = bind(_fd, (sockaddr *)&addr, sizeof(addr));
		if(ret < 0)
		{
			perror("bind");
			return false;
		}
		return true;
	}

	bool _listen(int num) const
	{
		int ret = listen(_fd, num);
		if(ret < 0)
		{
			perror("listen");
			return false;
		}
		return true;
	}

	bool _accept(tcp_socket *peer, std::string *ip = nullptr, uint16_t *port = nullptr) const
	{
		sockaddr_in peer_addr;
		socklen_t len = sizeof(peer_addr);
		int new_sock = accept(_fd, (sockaddr *)&peer_addr, &len);
		if(new_sock < 0)
		{
			perror("accept");
			return false;
		}
		peer->_fd = new_sock;
		if(ip != nullptr)
		{
			*ip = inet_ntoa(peer_addr.sin_addr);
		}
		if(port != nullptr)
		{
			*port = ntohs(peer_addr.sin_port);
		}
		return true;
	}

	bool _recv(std::string *buf) const
	{
		buf->clear();
		char tmp[1024 * 10] = {};
		ssize_t read_size = recv(_fd, tmp, sizeof(tmp), 0);
		if(read_size < 0)
		{
			perror("recv");
			return false;
		}
		if(read_size == 0)
		{
			return false;
		}
		buf->assign(tmp, read_size);
		return true;
	}

	bool _send(const std::string& buf) const
	{
		ssize_t write_size = send(_fd, buf.data(), buf.size(), 0);
		if(write_size < 0)
		{
			perror("send");
			return false;
		}
		return true;
	}

	bool _connect(const std::string& ip, uint16_t port) const
	{
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		addr.sin_port = htons(port);

		int ret = connect(_fd, (sockaddr *)&addr, sizeof(addr));
		if(ret < 0)
		{
			perror("connect");
			return false;
		}
		return true;
	}

	int _get_fd() const
	{
		return _fd;
	}
};
