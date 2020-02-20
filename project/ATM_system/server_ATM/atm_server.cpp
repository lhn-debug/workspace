
#include"tcp_multithread_server.hpp"
#include"../include/card_info.hpp"
#include"../include/myalgorithm.hpp"
#include"../mysql/mysql_con.hpp"
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>

using namespace std;

void handler(const std::string& req, std::string *resp)
{
	char ch = req[0];

	if(ch == 'A')
	{
		vector<string> split_req = split_string(req);
		
		srand((unsigned long)time(nullptr));
		long new_card_num = 1000000000 + rand() % 1000000000;
		
		char ch[20];
		sprintf(ch, "%ld", new_card_num);
		string tmp(ch), spa("");
		
		mysql_oper mo;
		while(mo._select_cond_card_num_judge_repet(tmp) != spa)
		{
			new_card_num = 1000000000 + rand() % 1000000000;
			sprintf(ch, "%ld", new_card_num);
			tmp.clear();
			tmp = ch;
		}
		
		string init_pswd("000000");
		
		mo._insert(split_req[0], split_req[1], tmp, init_pswd, 0);
		
		*resp = tmp;
	}
	else if(ch == 'B')
	{
		vector<string> split_req = split_string(req);
		
		mysql_oper mo;
		string res = mo._select_cond_card_num_find_pswd(split_req[0]);
		
		if(res == split_req[1])
		{
			*resp = split_req[0];
		}
		else
		{
			string tmp("None");
			*resp = tmp;
		}
	}
	else if(ch == '1')
	{
		vector<string> split_req = split_string(req);
		
		mysql_oper mo;
		string res = mo._select_cond_card_num_find_balance(split_req[0]);
		
		*resp = res;
	}
	else if(ch == '2')
	{
		vector<string> split_req = split_string(req);
		
		mysql_oper mo;
		string res = mo._update_cond_card_num_desposit(split_req[0], split_req[1]);
		
		if(res == split_req[0])
		{
			string succ("Successful!");
			*resp = succ;
		}
		else
		{
			string fail("Failured!");
			*resp = fail;
		}
	}
	else if(ch == '3')
	{
		vector<string> split_req = split_string(req);
		
		mysql_oper mo;
		string row, spa("");
		if((row = mo._select_cond_card_num_judge_repet(split_req[1])) != spa)
		{
			string res_a = mo._update_cond_card_num_desposit(split_req[1], split_req[2]);
			
			string sub = "-" + split_req[2];
			string res_s = mo._update_cond_card_num_desposit(split_req[0], sub);
			
			if(res_a == split_req[1] && res_s == split_req[0])
			{
				string succ("Successful!");
				*resp = succ;
			}
			else
			{
				string fail("Failured!");
				*resp = fail;
			}
		}
	}
	else if(ch == '4')
	{
		vector<string> split_req = split_string(req);
		
		mysql_oper mo;
		string res = mo._update_cond_card_num_desposit(split_req[0], split_req[1]);
		
		if(res == split_req[0])
		{
			string succ("Successful!");
			*resp = succ;
		}
		else
		{
			string fail("Failured!");
			*resp = fail;
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	if(argc < 0)
	{
		printf("Use ./dict_server [IP] [PORT]\n");
		return 1;
	}
	
	tcp_multithread_server server(argv[1], atoi(argv[2]));
	server._start(handler);
	
	return 0;
}
