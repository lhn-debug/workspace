#include "client.hpp"

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Usage:[./main_client <IP> <PORT>]");
		exit(1);
	}

	client _client(argv[1], atoi(argv[2]));

	if(!_client._connect())
	{
		printf("connect faliured!\n");
		exit(1);
	}

	while(true)
	{
		printf("# ");
		std::string req;
		getline(std::cin, req);
		_client._send(req);
		std::string resp;
		_client._recv(&resp);
		time_t timep;
		time(&timep);
		printf("%s\n%s\n", asctime(gmtime(&timep)), resp.c_str());
	}
	return 0;
}
