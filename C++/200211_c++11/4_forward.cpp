#include<iostream>

using namespace std;

void fun(int& x){cout<<"lval ref"<<endl;}
void fun(int&& x){cout<<"rval ref"<<endl;}
void fun(const int& x){cout<<"const lval ref"<<endl;}
void fun(const int&& x){cout<<"const rval ref"<<endl;}

template<typename T>
void perfect_forward(T&& t)
{
	fun(forward<T>(t));
}

int main()
{
	perfect_forward(10);//lr

	int a = 0;
	perfect_forward(a);//rr
	perfect_forward(move(a));//lr

	const int b = 0;
	perfect_forward(b);//clr
	perfect_forward(move(b));//crr
	return 0;
}
