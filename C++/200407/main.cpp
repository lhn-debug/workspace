#include<iostream>
#include<string>

#define FUNC(A, B, C, D) (A) + (B) * (C) - (D)

using namespace std;

//void info(string id ,string name);

void info(const char* id="436763",const char* name="fgdfg")
{
	cout<<id<<endl;
	cout<<name<<endl;
}
int Sub(int a,int b)
{
	return a-b;
}
double Sub(double a,double b)
{
	return a-b;
}
long Sub(long a,long b)
{
	return a-b;
}
int& fun(int& var)
{
	var+=1;
	return var;
}
int main()
{
/*	string a;
//	cin>>a;
	getline(cin,a);
	cout<<a<<endl;
*//*
	info();
	info("12356");
	info("12356", "asdasdas");
*//*
	cout<<Sub(1,3)<<endl;
	cout<<Sub(1.0,2.6)<<endl;
	cout<<Sub(13434,6788)<<endl;
*/
	int a = 10;
	int * p = &a;
	int& ref_a = a;
	cout<<*p<<endl;
	cout<<ref_a<<endl;
	cout<<fun(a)<<endl;
	cout<<FUNC(1, 2, FUNC(1, 2, 3, 4), 4)<<endl;;
	return 0;
}
/*
void info(const char* id="436763",const char* name="fgdfg")
{
	cout<<id<<endl;
	cout<<name<<endl;
}*/
