#include "tcp_multithread_server.hpp"
#include <unistd.h>

using namespace std;

void executeCMD(const char *cmd, char *result)
{
    char buf_ps[2048];
    char ps[2048] = {0};
    FILE *ptr;
    strcpy(ps, cmd);
    if((ptr = popen(ps, "r")) != NULL)
    {
        while(fgets(buf_ps, 2048, ptr) != NULL)
        {
           strcat(result, buf_ps);
           if(strlen(result) > 2048)
               break;
        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", ps);
    }
}

void handler(const std::string& req, std::string* resp)
{
	if(strcmp(req.substr(0, 2).c_str(), "cd") == 0)
	{
		chdir(req.substr(3, req.size()).c_str());	
		*resp = "OK!";
	}
	else
	{
		char res[2048];
		executeCMD(req.c_str(), res);
		string tmp(res);
		*resp = tmp + "\nOK!\n";
	}
	return ;
}

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		printf("Usage:[./main_server <IP> <PORT>]\n");
		exit(0);
	}
	tcp_multithread_server _server(argv[1], atoi(argv[2]));
	_server._start(handler);
	return 0;
}
