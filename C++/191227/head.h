#include<iostream>

using namespace std;

class Date
{
public:
	void display()
	{
		cout<<_y<<" "<<_m<<" "<<_d<<endl;
	}
	void setDate(int y,int m,int d)
	{
		_y=y;
		_m=m;
		_d=d;
	}
private:
	int _y;
	int _m;
	int _d;
};
