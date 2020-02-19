#pragma once

#include<string>
#include<stdio.h>

using namespace std;

class card_info
{
private:
	std::string _id_num;
	std::string _name;
	std::string _card_num;
	std::string _pswd;
	long _money;
public:
	card_info()
	{}

	card_info(const string& id_num, const string& name, const string& card_num = "", const string& pswd = "", const long& money = 0)
		:_id_num(id_num),_name(name),_card_num(card_num),_pswd(pswd),_money(money)
	{}

	void set_id_num(const string& id_num)
	{
		_id_num = id_num;
	}

	void set_name(const string& name)
	{
		_name = name;
	}

	void set_card_num(const string& card_num)
	{
		_card_num = card_num;
	}

	void set_pswd(const string& pswd)
	{
		_pswd = pswd;
	}

	void set_money(const long& money)
	{
		_money = money;
	}

	string get_id_num()
	{
		return _id_num;
	}

	string get_name()
	{
		return _name;
	}

	string get_card_num()
	{
		return _card_num;
	}

	string get_pswd()
	{
		return _pswd;
	}

	long get_money()
	{
		return _money;
	}

	string toString()
	{
		char str[1024];
		sprintf(str, "%s %s %s %s %ld", get_id_num().c_str(), get_name().c_str(), get_card_num().c_str(), get_pswd().c_str(), get_money());
		string ret(str);
		return ret;
	}
};
