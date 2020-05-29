#include "tcp_socket.hpp"
#include <functional>

typedef std::function<void (const std::string& req, std::string* resp)> Handler;

class server
{
	private:
		tcp_socket _sock;
		std::string _ip;
		std::uint16_t _port;

	public:
		server(const std::string& ip, const std::uint16_t port):_ip(ip),_port(port)
		{}

		~server()
		{
			_sock._close();
		}

		bool _start(Handler _handler)
		{
			CHECK_RET(_sock._socket());
			CHECK_RET(_sock._bind(_ip, _port));
			CHECK_RET(_sock._listen(5));
			
			while(true)
			{
				tcp_socket _newSock;
				std::string ip;
				std::uint16_t port = 0;
				
				if(!_sock._accept(&_newSock, &ip, &port))
				{
					continue;
				}

				printf("[client @%s:%d connect...]\n", ip.c_str(), port);

				while(true)
				{
					std::string req;
					if(!_newSock._recv(&req))
					{
						printf("[client @%s:%d disconnect...]\n", ip.c_str(), port);
						_newSock._close();
						break;
					}

					std::string resp;
					_handler(req, &resp);
					_newSock._send(resp);
					
					time_t timep;
					time(&timep);
					printf("%s", asctime(gmtime(&timep)));
					printf("[@%s:%d] req{%s} resp{%s}\n", ip.c_str(), port, req.c_str(), resp.c_str());
				}
			}
			return 0;
		}
};
