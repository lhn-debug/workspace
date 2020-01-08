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
	Date* operator&()
	{
		return this;
	}
	const Date* operator&() const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	const Date d2;
	cout<<&d1<<endl;
	cout<<&d2<<endl;
	return 0;
}
