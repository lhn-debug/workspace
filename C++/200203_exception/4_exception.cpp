#include<iostream>
#include<vector>

using namespace std;

int main()
{
	try
	{
		vector<int> v(10, 5);
		v.reserve(100000000000);//std::bad_alloc
		v.at(10) = 100;//vector::_M_range_check
	}
	catch(const exception& e)
	{
		cout<<e.what()<<endl;
	}
	catch(...)
	{
		cout<<"UnKnown Exception"<<endl;
	}
	return 0;
}
