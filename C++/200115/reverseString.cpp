#include<iostream>

using namespace std;

string reverseString(string s)
{
	if(s.empty())
	{
		return s;
	}
	size_t start = 0;
	size_t end = s.size() - 1;
	while(start < end)
	{
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}

int main()
{
	string s("hello");
	string str = reverseString(s);
	cout<<s<<endl;
	cout<<str<<endl;
	return 0;
}
