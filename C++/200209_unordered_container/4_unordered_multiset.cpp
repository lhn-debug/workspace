#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main()
{
	unordered_multiset<int> ums;
	ums.insert(3);
	ums.insert(4);
	ums.insert(5);
	ums.insert(3);
	ums.insert(4);
	ums.insert(2);
	ums.insert(1);
	ums.insert(7);
	for(auto& e : ums)
	{
		cout<<e<<endl;
	}
	for(int i = 0; i < ums.bucket_count(); ++i)
	{
		cout<<ums.bucket_size(i)<<endl;
	}
	return 0;
}
