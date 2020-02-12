#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void test_1()
{
	int arr[] = {1, 4, 2, 7, 3, 8, 5, 6, 9, 3, 0, 6};
	sort(arr, arr + sizeof(arr)/sizeof(int));
	sort(arr, arr + sizeof(arr)/sizeof(int), greater<int>());
	for(auto e : arr)
	{
		cout<<e<<" ";
	}
	cout<<endl;
}

struct goods
{
	string _name;
	double _price;
};

struct compare
{
	bool operator()(const goods& g1, const goods& g2)
	{
		return g1._price <= g2._price;
	}
};

void test_2()
{
	goods g[] = {{"a", 1.2}, {"d", 4.2}, {"b", 2.3} ,{"c", 3.7}};
	sort(g, g + sizeof(g)/sizeof(goods), compare());
	for(int i = 0; i < sizeof(g)/sizeof(goods); ++i)
	{
		cout<<g[i]._name<<" ";
	}
	cout<<endl;
}

void test_3()
{
	goods g[] = {{"a", 1.2}, {"d", 4.2}, {"b", 2.3} ,{"c", 3.7}};
	sort(g, g + sizeof(g)/sizeof(goods),
		[](const goods& g1, const goods& g2)
		{
			return g1._price <= g2._price;
		});
	for(int i = 0; i < sizeof(g)/sizeof(goods); ++i)
	{
		cout<<g[i]._name<<" ";
	}
	cout<<endl;
}

void test_4()
{
	[]{};

	int a = 3, b = 4;
	auto fun0 = [=]{return a + 3;};
	cout<<fun0()<<endl;

	auto fun1 = [&](int c){b = a + c;};
	fun1(10);
	cout<<b<<endl;

	auto fun2 = [=, &b](int c)->int{return b+= a + c;};
	cout<<fun2(10)<<endl;

	int x = 10;
	auto add_x = [x](int a)mutable->int{x *= 2; return a + x;};
	cout<<add_x(10)<<endl;
}

void (*PF)();
void test_5()
{
	auto fun1 = []{cout<<"fun1"<<endl;};
	auto fun2 = []{cout<<"fun2"<<endl;};
//	fun1 = fun2;
	auto fun3(fun2);
	fun3();
	PF = fun2;
	PF();
}

class Rate
{
private:
	double _rate;
public:
	Rate(double rate):_rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * year * _rate;
	}
};

void test_6()
{
	double rate = 0.49;
	Rate r1(rate);
	cout<<r1(10000.0, 2)<<endl;

	auto r2 = [=](double money, int year)->double{return money * year * rate;};
	cout<<r2(10000.0, 2)<<endl;
}

int main()
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	return 0;
}
