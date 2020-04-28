#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
class String
{
	private:
		char* _str;
	public:
		String(const char* str="fgh")
		{
			_str=(char *)malloc(strlen(str)+1);
			strcpy(_str,str);
		}
		~String()
		{
			cout<<"~String()"<<endl;
			free(_str);
		}


};
class Person
{
	private:
		String _name;
		int _age;
};

