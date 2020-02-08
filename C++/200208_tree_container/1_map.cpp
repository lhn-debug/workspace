#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("c", "C"));
	m.insert(make_pair("b", "B"));
	m["a"] = "A";
	auto ret = m.insert(make_pair("a", "S"));
	if(!ret.second)
	{
		cout<<ret.first->first<<","<<ret.first->second<<" always exists, insert failure!"<<endl;
	}
	m.erase("a");
	if(m.count("a") == 1)
	{
		cout<<"a exists!"<<endl;
	}
	else
	{
		cout<<"a not exists!"<<endl;
	}
	for(auto& e : m)
	{
		cout<<e.first<<"->"<<e.second<<endl;
	}
	return 0;
}
