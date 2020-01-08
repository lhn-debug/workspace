#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
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

	Date& operator=(const Date& date)
	{
		if(this != &date)
		{
			_year = date._year;
			_month = date._month;
			_day = date._day;
		}
	}

	bool operator==(const Date& date) const
	{
		return (_year == date._year)
			&&(_month == date._month)
			&&(_day == date._day);
	}

	bool operator!=(const Date& date) const
	{
		return (_year != date._year)
			||(_year != date._year)
			||(_year != date._year);
	}

	bool operator>=(const Date& date) const
	{
		if(_year >= date._year)
		{
			if(_year > date._year)return 1;
			else
			{
				if(_month >= date._month)
				{
					if(_month > date._month)return 1;
					else
					{
						if(_day >= date._day)return 1;
						else
						{
							return 0;
						}
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}

	bool operator<=(const Date& date) const
	{
		if(_year <= date._year)
		{
			if(_year < date._year)return 1;
			else
			{
				if(_month <= date._month)
				{
					if(_month < date._month)return 1;
					else
					{
						if(_day <= date._day)return 1;
						else
						{
							return 0;
						}
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}

	Date& operator++()
	{
		int month_pool[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		if((_year % 4 == 0 && _year % 100 != 0)||(_year % 400 == 0))
		{
			month_pool[1]=29;
		}
		if(_day < month_pool[_month-1])
		{
			_day += 1;
		}
		else if(_month < 12)
		{
			_month += 1;
			_day = 1;
		}
		else
		{
			_year += 1;
			_month = 1;
			_day = 1;
		}
	}

	Date operator++(int)
	{
		Date old(*this);
		++old;
		return old;
	}

	Date operator+(int days)
	{
		Date old(*this);
		for(int i = 0; i < days; i++)
		{
			++old;
		}
		return old;
	}

	void display() const
	{
		cout<<_year<<"/"<<_month<<"/"<<_day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1999,1,1);
	d1.display();

	Date d2(2019,1,1);
	d2.display();

	Date d3(d2);
	d3.display();

	Date d4 = d1;
	d4.display();

	cout<<(d1 == d4)<<endl;
	cout<<(d1 == d3)<<endl;
	cout<<(d1 != d3)<<endl;
	cout<<(d1 != d4)<<endl;
	cout<<(d1 >= d2)<<endl;
	cout<<(d2 >= d3)<<endl;
	cout<<(d3 >= d4)<<endl;
	cout<<(d1 <= d2)<<endl;
	cout<<(d2 <= d3)<<endl;
	cout<<(d3 <= d4)<<endl;

	Date d5(2019,12,29);
	Date d6(2019,12,31);
	Date d7(2019,2,28);
	Date d8(2020,2,28);
	Date d9(2020,2,29);
	Date d0(2000,2,28);

	
	(++d5).display();
	(++d6).display();
	(++d7).display();
	(++d8).display();
	(++d9).display();
	(++d0).display();
	
	(d5++).display();
	(d6++).display();
	(d7++).display();
	(d8++).display();
	(d9++).display();
	(d0++).display();

	cout<<endl;
	Date d(2018,2,9);
	d.display();
	(d+688).display();
	return 0;
}
