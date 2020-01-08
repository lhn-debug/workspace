#include<iostream>

using namespace std;

class Date;
class Time
{
friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour), _minute(minute), _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{}
	void setTime(int hour, int minute, int second)
	{
		_time._hour = hour;
		_time._minute = minute;
		_time._second = second;
	}
	void display()
	{
		cout<<_year<<"-"<<_month<<"-"<<_day<<" "<<_time._hour<<":"<<_time._minute<<":"<<_time._second<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _time;
};

int main()
{
	Date d(2020,1,2);
	d.setTime(21,36,20);
	d.display();
	return 0;
}
