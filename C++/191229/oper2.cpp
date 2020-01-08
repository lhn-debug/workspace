#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(const Date& d)
	{
		return (_year == d._year)
			&&(_month == d._month)
			&&(_day == d._day);
	}
	Date& operator=(const Date& d)
	{
		if(this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
public:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2019,12,29);
	d1 = d2;
	cout<<(d1 == d2)<<endl;
	return 0;
}
