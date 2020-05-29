#include "tcp_socket.hpp"

class client
{
	private:
		tcp_socket _sock;
		std::string _ip;
		std::uint16_t _port;

	public:
		client(const std::string& ip, const uint16_t& port):_ip(ip),_port(port)
		{
			_sock._socket();
		}

		~client()
		{
			_sock._close();
		}

		bool _connect()
		{
			return _sock._connect(_ip, _port);
		}

		bool _send(const std::string& buf)
		{
			return _sock._send(buf);
		}

		bool _recv(std::string* buf)
		{
			return _sock._recv(buf);
		}
};
