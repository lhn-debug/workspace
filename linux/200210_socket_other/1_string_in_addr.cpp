#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using namespace std;

int main()
{
	struct sockaddr_in addr;
	inet_aton("127.0.0.1", &addr.sin_addr);
	uint32_t* ptr = (uint32_t *)(&addr.sin_addr);
	printf("%X\n", htonl(*ptr));
	cout<<inet_ntoa(addr.sin_addr)<<endl;
	return 0;
}
