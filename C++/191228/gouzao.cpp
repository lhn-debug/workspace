#include"head.h"

using namespace std;

void Date::display()
{
	cout<<_year<<" "<<_month<<" "<<_day<<endl;
}

int main()
{
	Date d;
	d.display();
	return 0;
}
