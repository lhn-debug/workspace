#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	multimap<string, string> mm;
	mm.insert(pair<string, string>("c", "C"));
	mm.insert(make_pair("b", "B"));
	mm.insert(make_pair("b", "C"));
	for(auto& e : mm)
	{
		cout<<e.first<<"->"<<e.second<<endl;
	}
	return 0;
}
