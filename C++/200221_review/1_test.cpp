#include<iostream>
#include<string>

using namespace std;

//cin与getline
void test_1()
{
	string s1, s2;
	cin>>s1;
	cout<<s1<<endl;
	getline(cin, s2);
	cout<<s2<<endl;
}

void fun(int a)
{
	cout<<a<<endl;
}

void fun(string& s)
{
	cout<<s<<endl;
}

class A
{
private:
	int a;
	char b;
	static double c;
public:
	void display()
	{
		cout<<a<<endl;
		cout<<b<<endl;
	}

	static double get_c()
	{
		return c;
	}
/*
	static char get_b()
	{
		return b;
	}
*/
};

double A::c = 1.23456;

int main()
{
	//test_1();
	
/*	fun(1);
	string s("aaa");
	fun(s);
	
	A a;
	a.display();
	cout<<sizeof(int)<<" "<<sizeof(char)<<" "<<sizeof(A)<<" "<<sizeof(a)<<endl;
*/	
	string s("\\");
	cout<<s<<endl;
	return 0;
}
