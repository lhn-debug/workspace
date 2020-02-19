#pragma once

#include"../include/card_info.hpp"
#include"tcp_client.hpp"
#include<iostream>
#include<unistd.h>

using namespace std;

class screen_display
{
public:
	void _register()
	{
		system("clear");
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|             WELCOME TO ATM! PLEASE OPERATION WITH TIPS!             |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|---------------------------------------------------------------------|"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                     PLEASE INPUT MESSAGE FOLLOW                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                            1.ID CARD NUMBER                         |"<<endl;
		cout<<"|                            2.YOUR NAME                              |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                            PLEASE INPUT!                            |"<<endl;
		cout<<"-----------------------------------------------------------------------"<<endl;
	}

	void _work()
	{
		system("clear");
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|             WELCOME TO ATM! PLEASE OPERATION WITH TIPS!             |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|---------------------------------------------------------------------|"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                     PLEASE INPUT MESSAGE FOLLOW                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|            1.Check Balance                   3.Transfer             |"<<endl;
		cout<<"|            2.Deposit                         4.Withdraw             |"<<endl;
		cout<<"|                               0.Exit                                |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                            PLEASE INPUT!                            |"<<endl;
		cout<<"-----------------------------------------------------------------------"<<endl;
	}

	void _login()
	{
		system("clear");
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|             WELCOME TO ATM! PLEASE OPERATION WITH TIPS!             |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|---------------------------------------------------------------------|"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                     PLEASE INPUT MESSAGE FOLLOW                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                            1.ID CARD NUMBER                         |"<<endl;
		cout<<"|                            2.YOUR PASSWORD                          |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                            PLEASE INPUT!                            |"<<endl;
		cout<<"-----------------------------------------------------------------------"<<endl;
	}
	
	void _error()
	{
		cout<<"input error!"<<endl;
		sleep(1);
	}
	
	void display()
	{
		system("clear");
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|             WELCOME TO ATM! PLEASE OPERATION WITH TIPS!             |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|---------------------------------------------------------------------|"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                             A  Register                             |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                             B  Login                                |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                                                                     |"<<endl;
		cout<<"|                            PLEASE INPUT!                            |"<<endl;
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout<<">>";
	}
};
