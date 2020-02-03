#include<iostream>
#include<memory>

using namespace std;

class Date
{
public:
	Date()
	{
		cout<<"Date()"<<endl;
	}

	~Date()
	{
		cout<<"~Date()"<<endl;
	}
public:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date * date = new Date();
	auto_ptr<Date> ap(date);
	//auto_ptr<Date> cp(ap);
	ap->_year = 2020;
	return 0;
}
