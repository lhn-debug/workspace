#include"display.hpp"
#include<iostream>

using namespace std;

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		cout<<"Use Format './dict_client [IP] [PORT]'"<<endl;
		return 1;
	}
//	tcp_client client(argv[1], atoi(argv[2]));
//	if(!client._connect())
//	{
//		return 1;
//	}
//	screen_display sd;
	while(true)
	{
		tcp_client client(argv[1], atoi(argv[2]));
		if(!client._connect())
		{
			return 1;
		}
		screen_display sd;
		string input;
		sd.display();
		cin>>input;
		if(input == "A")
		{
			sd._register();
			string id_num, name;
			cout<<"ID Card Number >> ";
			cin>>id_num;
			cout<<"Your Name >> ";
			cin>>name;
			card_info ci(id_num, name);
			string req = input + "|" + ci.toString();
			client._send(req);
			string res;
			client._recv(&res);
			cout<<"Your ID Card Number : "<<res<<endl;
			sleep(10);
		}
		else if(input == "B")
		{
			sd._login();
			string id_num, pswd;
			cout<<"ID Card Number >> ";
			cin>>id_num;
			cout<<"Your Password >> ";
			cin>>pswd;
			string req = input + "|" + id_num + " " + pswd;
			client._send(req);
			string res, tmp("None");
			client._recv(&res);
			while(true)
			{
				if(res == id_num)
				{
					sd._work();
					string choose;
					cout<<"Please Choose Service >> ";
					cin>>choose;
					if(choose == "0")
					{
						cout<<"exit..."<<endl;
						sleep(2);
						break;
					}
					else if(choose == "1")
					{
						string req = choose + "|" + id_num;
						client._send(req);
						string res;
						client._recv(&res);
						cout<<"Your Balance : "<<res<<endl;
						sleep(5);
					}
					else if(choose == "2")
					{
						string bal;
						cout<<"Please Put Money >> ";
						cin>>bal;
						string req = choose + "|" + id_num + " " + bal;
						client._send(req);
						string res;
						client._recv(&res);
						cout<<"Desposit "<<res<<endl;
						sleep(5);
					}
					else if(choose == "3")
					{
						string card, mon;
						cout<<"Please Input Chamber Payee Card Number >> ";
						cin>>card;
						cout<<"Please Input Transfer Money >> ";
						cin>>mon;
						string req = choose + "|" + id_num + " " + card + " " + mon;
						client._send(req);
						string res;
						client._recv(&res);
						cout<<"Transfer "<<res<<endl;
						sleep(5);
					}
					else if(choose == "4")
					{
						string bal;
						cout<<"Please Input Withdraw Money >> ";
						cin>>bal;
						string req = choose + "|" + id_num + " " + "-" + bal;
						client._send(req);
						string res;
						client._recv(&res);
						cout<<"Withdraw "<<res<<endl;
						sleep(5);
					}
					else
					{
						sleep(2);
						break;
					}
				}
				else
				{
					sleep(2);
					break;
				}
			}
		}
		else
		{
			sd._error();
			continue;
		}
	}
	return 0;
}
