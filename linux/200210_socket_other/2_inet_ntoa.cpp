#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>

using namespace std;

void * fun1(void * arg)
{
	struct sockaddr_in* addr = (struct sockaddr_in*)arg;
	while(1)
	{
		cout<<"addr1:"<<inet_ntoa(addr->sin_addr)<<endl;
		sleep(1);
	}
	return nullptr;
}

void * fun2(void * arg)
{
	struct sockaddr_in* addr = (struct sockaddr_in*)arg;
	while(1)
	{
		cout<<"addr2:"<<inet_ntoa(addr->sin_addr)<<endl;
		sleep(1);
	}
	return nullptr;
}

int main()
{
	pthread_t tid1;
	pthread_t tid2;
	struct sockaddr_in addr1;
	struct sockaddr_in addr2;
	addr1.sin_addr.s_addr = 0;
	addr2.sin_addr.s_addr = 0xffffffff;
	pthread_create(&tid1, nullptr, fun1, &addr1);
	pthread_create(&tid2, nullptr, fun2, &addr2);
	pthread_join(tid1, nullptr);
	pthread_join(tid2, nullptr);
	return 0;
}
