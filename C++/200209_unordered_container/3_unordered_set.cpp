#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main()
{
	unordered_set<string> us;
	us.insert("A");
	us.insert("B");
	us.insert("C");
	us.insert("D");
	us.insert("E");
	us.insert("F");
	us.insert("G");
	for(auto& e : us)
	{
		cout<<e<<endl;
	}
	for(int i = 0; i < us.bucket_count(); ++i)
	{
		cout<<us.bucket_size(i)<<endl;
	}
	cout<<endl;
	unordered_set<int> usi;
	usi.insert(2);
	usi.insert(4);
	usi.insert(2);
	usi.insert(3);
	usi.insert(2);
	usi.insert(1);
	for(auto& e : usi)
	{
		cout<<e<<endl;
	}
	for(int i = 0; i < usi.bucket_count(); ++i)
	{
		cout<<usi.bucket_size(i)<<endl;
	}
	return 0;
}
