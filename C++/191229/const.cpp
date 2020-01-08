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
	void display()
	{
		display2();
	}
	void display2() const
	{
		cout<<"display() const:"<<_year<<_month<<_day<<endl;
	}
public:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019,12,29);
	d1.display();
	return 0;
}
