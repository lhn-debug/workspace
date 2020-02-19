#pragma once

#include<my_global.h>
#include<mysql.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include"../include/card_info.hpp"
#include"../include/myalgorithm.hpp"

using namespace std;

static const char * host = "localhost";
static const char * user = "root";
static const char * password = "123456";
static const char * database = "card";

class mysql_oper
{
private:
	MYSQL * con;
private:
	static void finish_with_error(MYSQL * con)
	{
		fprintf(stderr, "MYSQL Running Error: %s\n", mysql_error(con));
		if(con)
		{
			mysql_close(con);
		}
		exit(EXIT_FAILURE);
	}

	void query_result(vector<string>& ret)
	{
		MYSQL_RES * res = mysql_store_result(con);
		if(res == nullptr)
		{
			finish_with_error(con);
		}
	
		int num_fields = mysql_num_fields(res);
		cout<<"rows count:"<<num_fields<<endl;
	
		MYSQL_ROW row;
		while(row = mysql_fetch_row(res))
		{
			string s;
			for(int i = 0; i < num_fields; ++i)
			{
				//cout<<row[i]<<" ";
				s += row[i];
				s += " ";
			}
			ret.push_back(s);
			//cout<<endl;
		}
		
		mysql_free_result(res);
	}
public:
	mysql_oper()
	{
		con = mysql_init(nullptr);
		if(con == nullptr)
		{
			finish_with_error(con);
		}
		
		if(mysql_real_connect(con, host, user, password, database, 0, nullptr, 0) == nullptr)
		{
			finish_with_error(con);
		}

		if(mysql_set_character_set(con, "utf8") != 0)
		{
			finish_with_error(con);
		}
	}
	
	~mysql_oper()
	{
		mysql_close(con);
	}

	void _insert(const string& id_num, const string& name, const string& card_num = "", const string& pswd = "", const long& money = 0)
	{
		char insert[1000];
		sprintf(insert, "insert into card_info values('%s', '%s', '%s', '%s', %ld)", id_num.c_str(), name.c_str(), card_num.c_str(), pswd.c_str(), money);
		cout<<insert<<endl;
		
		if(mysql_query(con, insert))
		{
			finish_with_error(con);
		}
	}

	vector<string> _selectAll()
	{
		char query[1000];
		sprintf(query, "select * from card_info");
		cout<<query<<endl;
		
		if(mysql_query(con, query))
		{
			finish_with_error(con);
		}
		vector<string> ret;
		query_result(ret);
		return ret;
	}

	string _select_cond_card_num_judge_repet(string card_num)
	{
		string ret("");
		vector<string> all = _selectAll();
		for(int i = 0; i < all.size(); i++)
		{
			vector<string> tmp = split_string(all[i]);
			if(tmp[2] == card_num)
			{
				ret = all[i];
				break;
			}
		}
		return ret;
	}

	string _select_cond_card_num_find_pswd(string card_num)
	{
		string ret("");
		vector<string> all = _selectAll();
		for(int i = 0; i < all.size(); i++)
		{
			vector<string> tmp = split_string(all[i]);
			if(tmp[2] == card_num)
			{
				ret = tmp[3];
				return ret;
			}
		}
		return ret;
	}

	string _select_cond_card_num_find_balance(string card_num)
	{
		string ret("");
		vector<string> all = _selectAll();
		for(int i = 0; i < all.size(); i++)
		{
			vector<string> tmp = split_string(all[i]);
			if(tmp[2] == card_num)
			{
				ret = tmp[4];
				return ret;
			}
		}
		return ret;
	}

	string _update_cond_card_num_desposit(string card_num, string money)
	{
		string ret("");
		char update[1000];
		sprintf(update, "update card_info set _money = _money + %d where _card_num = %s", atoi(money.c_str()), card_num.c_str());
		cout<<update<<endl;
		
		if(mysql_query(con, update))
		{
			finish_with_error(con);
			return ret;
		}
		return card_num;
	}
};
