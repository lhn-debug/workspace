#include<iostream>
#include<thread>
#include<atomic>

using namespace std;

atomic_long sum{0};

void fun(size_t num)
{
	for(size_t i = 0; i < num; ++i)
	{
		sum++;
	}
}

int main()
{
	cout<<sum<<endl;
	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();
	cout<<sum<<endl;
	return 0;
}
