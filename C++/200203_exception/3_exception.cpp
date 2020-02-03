#include<iostream>

using namespace std;

class Exception
{
protected:
	string _errmsg;
	size_t _id;
	//...
};

class SqlException:public Exception
{};

class CacheException:public Exception
{};

class HttpServerException:public Exception
{};

int main()
{
	try
	{
		//server.start();
	}
	catch(const Exception& e)
	{}
	catch(...)
	{
		cout<<"UnKnow Exception"<<endl;
	}
	return 0;
}
