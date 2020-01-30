#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct ServerConfig
{
	char _ip[32];
	size_t _port;
};

int main()
{
	ServerConfig wtsc, rdsc;
	strcpy(wtsc._ip, "192.168.1.1");
	wtsc._port = 8080;
/*
	ofstream ofs("serverconfig.bin", ifstream::in|ifstream::binary);
	ofs.write((const char *)&wtsc, sizeof(ServerConfig));
	ofs.close();

	ifstream ifs("serverconfig.bin", ifstream::out|ifstream::binary);
	ifs.read((char *)&rdsc, sizeof(ServerConfig));
	ifs.close();

	cout<<rdsc._ip<<endl;
	cout<<rdsc._port<<endl;
*/
	ofstream ofs("serverconfig.txt");
	ofs<<wtsc._ip<<endl;
	ofs<<wtsc._port<<endl;
	ofs.close();

	ifstream ifs("serverconfig.txt");
	ifs>>rdsc._ip;
	ifs>>rdsc._port;
	ifs.close();

	cout<<rdsc._ip<<endl;
	cout<<rdsc._port<<endl;
	return 0;
}
