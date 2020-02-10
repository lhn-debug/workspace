#include"udp_client.hpp"
#include<iostream>

using namespace std;

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		cout<<"Use Format './dict_client [IP] [PORT]'"<<endl;
		return 1;
	}
	udp_client client(argv[1], atoi(argv[2]));
	while(true)
	{
		string word;
		cout<<"Input a word you would find:";
		cin>>word;
		if(strcmp(word.c_str(), "exit") == 0)
		{
			char sure[5];
			cout<<"Are you sure exit?[Y/N]";
			cin>>sure;
			if(strcmp(sure, "Y") == 0)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		client._sendto(word);
		string res;
		client._recvfrom(&res);
		cout<<word<<" means "<<res<<endl;
	}
	return 0;
}
