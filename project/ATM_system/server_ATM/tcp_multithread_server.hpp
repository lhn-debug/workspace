#pragma once

#include"thread_pool.hpp"
#include<functional>
#include<pthread.h>

class tcp_multithread_server
{
private:
	tcp_socket _listen_sock;
	std::string _ip;
	uint16_t _port;
	ThreadPool pool;
public:
	tcp_multithread_server(const std::string& ip, uint16_t port):_ip(ip),_port(port)
	{
		pool.poolInit();
	}
/*
	static void* _thread_entry(void *arg)
	{
		thread_arg *p = reinterpret_cast<thread_arg *>(arg);
		_process_connect(p);
		p->new_sock._close();
		delete p;
		return nullptr;
	}
*/
	static bool _thread_entry(thread_arg *data)
	{
		thread_arg *p = data;
		_process_connect(p);
		p->new_sock._close();
		delete p;
		return true;
	}

	static void _process_connect(thread_arg *arg)
	{
		while(true)
		{
			std::string req;
			if(!arg->new_sock._recv(&req))
			{
				printf("[client %s:%d] disconnected...\n", arg->ip.c_str(), arg->port);
				break;
			}
			std::string resp;
			arg->handler(req, &resp);
			arg->new_sock._send(resp);
			printf("[client %s:%d] req:%s, resp:%s\n", arg->ip.c_str(), arg->port, req.c_str(), resp.c_str());
		}
	}

	bool _start(Handler handler)
	{
		CHECK_RET(_listen_sock._socket());
		CHECK_RET(_listen_sock._bind(_ip, _port));
		CHECK_RET(_listen_sock._listen(5));
		while(true)
		{
			thread_arg *arg = new thread_arg();
			arg->handler = handler;
			if(!_listen_sock._accept(&arg->new_sock, &arg->ip, &arg->port))
			{
				continue;
			}
			printf("[client %s:%d] connect...\n", arg->ip.c_str(), arg->port);
/*
			pthread_t tid;
			pthread_create(&tid, nullptr, _thread_entry, arg);
			pthread_detach(tid);
*/
			ThreadTask * tt = new ThreadTask(arg, _thread_entry);
			pool.pushTask(tt);
		}
		pool.poolQuit();
		return true;
	}
};
