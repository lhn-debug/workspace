#include<iostream>

using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T * ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if(_ptr)
		{
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T * _ptr;
};

struct Date
{
	int _year;
	int _month;
	int _day;
};

int main()
{
	int * tmp = new int();
	SmartPtr<int> sp(tmp);
	*sp = 10;
	cout<<"*sp:"<<*sp<<endl;
	cout<<"*tmp:"<<*tmp<<endl;

	Date * date = new Date();
	SmartPtr<Date> ss(date);
	ss->_year = 2020;
	ss->_month = 2;
	ss->_day = 3;
	cout<<date->_year<<"-"<<date->_month<<"-"<<date->_day<<endl;
	return 0;
}
