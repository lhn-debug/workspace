#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Use:./http_server [IP] [PORT]\n");
		return 1;
	}
	int fd;
	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		return 1;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));
	if(bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("bind");
		return 1;
	}
	if(listen(fd, 10) < 0)
	{
		perror("listen");
		return 1;
	}
	while(true)
	{
		struct sockaddr_in client_addr;
		socklen_t len;
		int client_fd = accept(fd, (struct sockaddr *)&client_addr, &len);
		if(client_fd < 0)
		{
			perror("accept");
			continue;
		}
		char input_buf[1024 * 10] = {};
		ssize_t read_size = read(client_fd, input_buf, sizeof(input_buf) - 1);
		if(read_size < 0)
		{
			return 1;
		}
		printf("[Request] %s", input_buf);
		char buf[1024] = {};
		const char * html = "<h1>Hello World!<h1>";
		sprintf(buf, "HTTP/1.0 200 OK\nContent-Length:%lu\n\n%s", strlen(html), html);
		printf("%s\n", buf);
		write(client_fd, buf, strlen(buf));
	}
	return 0;
}
