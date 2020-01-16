#include<iostream>

using namespace std;

int firstUniqChar(string s)
{
	if(s.empty())
	{
		return -1;
	}
	int count[256] = {0};
	for(int i = 0; i < s.size(); ++i)
	{
		count[s[i]]++;
	}
	for(int i = 0; i < s.size(); ++i)
	{
		if(count[s[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	string s = "dskasbfkaffnd";
	int pos = firstUniqChar(s);
	cout<<pos<<endl;
	cout<<s<<endl;
	if(pos != -1)
	{
		cout<<s[pos]<<endl;
	}
}
