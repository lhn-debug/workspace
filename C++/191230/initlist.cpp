#include<iostream>

using namespace std;

class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout<<"Time()"<<endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day = 0)
	{
		_day = day;
	}
private:
	int _day;
	Time _time;
};

int main()
{
	Date d(1);
	return 0;
}
