#include"head.h"

using namespace std;

int main()
{
	Date d1;
	Date d2(d1);
	d1.display();
	d2.display();
	return 0;
}
