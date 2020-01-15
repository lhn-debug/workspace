#include<iostream>
#include<cstring>

using namespace std;

void test_string_1()
{
	string s1("hello");
	const string s2("HELLO");
	cout<<s1<<" "<<s2<<endl;
	cout<<s1[0]<<" "<<s2[0]<<endl;
	s1[0] = 'H';
	cout<<s1<<endl;
	//s2[0] = 'h';const不可修改
}

void test_string_2()
{
	string s("Hello");

	//for+operator[]
	for(size_t i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;

	//迭代器
	string::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	string::reverse_iterator rit = s.rbegin();
	while(rit != s.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;

	//范围for:C++11
	for(auto ch : s)
	{
		cout<<ch<<" ";
	}
	cout<<endl;
}

int main()
{
	test_string_1();
	cout<<endl;
	test_string_2();
	return 0;
}
