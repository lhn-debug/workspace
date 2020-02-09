#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_multimap<int, string> umm;
	umm.insert(make_pair<int, string>(3, "C"));
	umm.insert(make_pair<int, string>(2, "B"));
	umm.insert(make_pair<int, string>(3, "C"));
	umm.insert(make_pair<int, string>(4, "D"));
	umm.insert(make_pair<int, string>(3, "C"));
	umm.insert(make_pair<int, string>(5, "E"));
	for(auto& e : umm)
	{
		cout<<e.first<<"|"<<e.second<<endl;
	}
	for(int i = 0; i < umm.bucket_count(); ++i)
	{
		cout<<umm.bucket_size(i)<<endl;
	}
	return 0;
}
