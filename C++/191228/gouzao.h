#include<iostream>

using namespace std;

class Time
{
	public:
		Time()
		{
			cout<<"Time()"<<endl;
			_hour = 0;
			_minute = 0;
			_second = 0;
		}
	private:
		int _hour;
		int _minute;
		int _second;
};

class Date
{
	public:
		void display();
	private:
		int _year;
		int _month;
		int _day;
		Time _time;	//自定义类型
};
