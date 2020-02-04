#include<iostream>
#include<memory>

using namespace std;

int main()
{
	int * tmp = new int();
	unique_ptr<int> up(tmp);
	*up = 10;
	cout<<*up<<" "<<*tmp<<endl;
	//unique_ptr<int> cp(up);防拷贝
	return 0;
}
