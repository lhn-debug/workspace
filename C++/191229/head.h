#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 2019, int month = 12, int day = 29)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	void display()
	{
		cout<<_year<<" "<<_month<<" "<<_day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
