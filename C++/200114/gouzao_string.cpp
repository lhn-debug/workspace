#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	string s1;
	string s2("hello");
	string s3(5, 'a');
	string s4(s3);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	return 0;
}
