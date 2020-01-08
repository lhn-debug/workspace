#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
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
public:
	int _year;
	int _month;
	int _day;
};

/*
bool operator==(const Date& d1, const Date& d2)
{
	return (d1._year == d2._year)
		&&(d1._month == d2._month)
		&&(d1._day == d2._day);
}
*/

int main()
{
	Date d1(2019,12,29);
	Date d2(2019,12,29);
	cout<<(d1 == d2)<<endl;
	return 0;
}
