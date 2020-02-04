#include<iostream>
#include<memory>

using namespace std;

int main()
{
	int * tmp = new int();
	shared_ptr<int> sp(tmp);
	shared_ptr<int> cp(sp);
	*sp = 10;
	cout<<*tmp<<" "<<*sp<<endl;
	*cp = 20;
	cout<<*tmp<<" "<<*sp<<endl;
	return 0;
}
