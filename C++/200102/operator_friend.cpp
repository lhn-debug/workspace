#include<iostream>

using namespace std;

class Date
{
friend ostream& operator<<(ostream& _cout, const Date& date);
friend istream& operator>>(istream& _cin, const Date& date);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& date)
{
	_cout<<date._year<<"-"<<date._month<<"-"<<date._day<<endl;
	return _cout;
}

istream& operator>>(istream& _cin, const Date& date)
{
	_cin>>date._year;
	_cin>>date._month;
	_cin>>date._day;
	return _cin;
}

int main()
{
	Date d;
	cin>>d;
	cout<<d<<endl;
	return 0;
}
