#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_multimap<string, string> umm;
	umm.insert(make_pair("main.hpp", "/home/src"));
	umm.insert(make_pair("main.hpp", "/home/src/lhn/200406"));
	umm.insert(make_pair("test.hpp", "/home/src"));
	umm.insert(make_pair("a.hpp", "/home/src"));
	umm.insert(make_pair("ma.hpp", "/home/src"));
	umm.insert(make_pair("in.hpp", "/home/src"));
	umm.insert(make_pair("mn.hpp", "/home/src"));
	umm.insert(make_pair("mn.hpp", "/home/src/lhn/text"));
	umm.insert(make_pair("in.hpp", "/home/bin/src/etc"));
	for(auto& e : umm)
	{
		cout<<e.first<<" "<<e.second<<endl;
	}
	cout<<umm.bucket_count()<<endl;
	
	for(int i = 0; i < umm.bucket_count(); i++)
	{
		for(unordered_multimap<string, string>::local_iterator li = umm.begin(i); li != umm.end(i); li++)
		{
			cout<<i<<" "<<(*li).first<<" "<<(*li).second<<endl;
		}
	}
	return 0;
}
