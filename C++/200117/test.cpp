/*
 *此程序会崩溃
 *由于s2对s1浅拷贝,导致多次释放同一块空间
 * */

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<assert.h>

using namespace std;

class String
{
public:
	String(const char * str = "")
	{
		if(nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String()
	{
		if(_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char * _str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	return 0;
}
