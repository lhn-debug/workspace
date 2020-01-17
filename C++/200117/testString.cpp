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
	String(const String& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
	}
	String& operator=(const String& str)
	{
		if(this != &str)
		{
			delete[] _str;
			_str = new char[strlen(str._str) + 1];
			strcpy(_str, str._str);
		}
		return *this;
	}
	~String()
	{
		if(_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	void display()
	{
		cout<<_str<<endl;
	}
private:
	char * _str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	String s3 = s2;
	s1.display();
	s2.display();
	s3.display();
	return 0;
}
