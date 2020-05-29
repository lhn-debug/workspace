#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str = "abcdefg/aaa";
	cout<<str.substr(str.rfind('/') + 1, str.size())<<endl;
	cout<<str.substr(0, str.rfind('/') + 1)<<endl;
	return 0;
}
