#include<iostream>

using namespace std;

class Date
{
public:
	
	Date(int year = 0)
		:_year(year)
	{}

	/*禁止单参构造函数的隐式转换
	explicit Date(int year = 0)
		:_year(year)
	{}
	*/
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2018);

	d = 2019;
	/*
	 *没有explicit关键字时，本句可以通过编译;
	 *加上后，禁止单参构造函数隐式转换，报错
	 *编译器将2019构造无名对象，给d赋值
	*/
	return 0;
}
