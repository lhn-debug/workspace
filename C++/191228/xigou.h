#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class String
{
public:
	String(const char* str = "tom")
	{
		_str = (char *)malloc(strlen(str)+1);
		strcpy(_str, str);
	}
	~String()
	{
		cout<<"~String()"<<endl;
		free(_str);
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	int _age;
};
