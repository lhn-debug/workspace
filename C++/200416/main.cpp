#include<iostream>
#include<string>
#include<map>

using namespace std;

static string PATH = "";

int main()
{
	PATH = "/home/host";
	cout<<PATH<<endl;
	size_t pos = PATH.rfind('/');
	cout<<pos<<endl;
	PATH.erase(pos, PATH.size());
	cout<<PATH<<endl;

	multimap<string, string> mp;
	mp.insert(make_pair("asd", "/sd/ad/adss"));
	mp.insert(make_pair("asd", "/sd/ad/adss/sdad"));
	mp.insert(make_pair("aasa", "/sd/ad/adss/ddd"));
	mp.insert(make_pair("asdsdsd", "/sd/ad/adss"));
	mp.insert(make_pair("assa", "/sd/ad/adss"));
	mp.insert(make_pair("asdsd", "/sd/ad/adss/b"));
	mp.insert(make_pair("asdaaa", "/sd/ad/adss/a"));
	mp.insert(make_pair("asdaad", "/sd/ad/adss/dsds"));

	auto beg = mp.lower_bound("asd");
	auto end = mp.upper_bound("asd");
	for(auto it = beg; it != end; it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
