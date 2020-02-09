#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<int, string> um;
	um.insert(make_pair<int, string>(2, "B"));
	um.insert(make_pair<int, string>(2, "C"));
	um.insert(make_pair<int, string>(1, "A"));
	um.insert(make_pair<int, string>(5, "E"));
	um.insert(make_pair<int, string>(4, "D"));
	for(auto& e : um)
	{
		cout<<e.first<<"|"<<e.second<<endl;
	}
	cout<<um.bucket_count()<<endl;
	for(int i = 0; i < um.bucket_count(); ++i)
	{
		cout<<um.bucket_size(i)<<endl;
	}
	return 0;
}
