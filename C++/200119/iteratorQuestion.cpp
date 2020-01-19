#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

	/*
	 * 本段程序会崩溃
	 * erase会导致it失效，对失效的迭代器进行++it，导致崩溃
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if(*it % 2 == 0)
		{
			v.erase(it);
		}
	}
	*/

	for(vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if(*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;

	return 0;
}
