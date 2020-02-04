#include<iostream>
#include<memory>

using namespace std;

template<class T>
class FreeFunc
{
public:
	void operator()(T * ptr)
	{
		cout<<"free:"<<ptr<<endl;
		free(ptr);
	}
};

template<class T>
class DeleteArrayFunc
{
public:
	void operator()(T * ptr)
	{
		cout<<"delete[]:"<<ptr<<endl;
		delete[] ptr;
	}
};

int main()
{
	FreeFunc<int> freefunc;
	shared_ptr<int> sp1((int *)malloc(sizeof(int) * 2), freefunc);
	DeleteArrayFunc<int> deletearrayfunc;
	shared_ptr<int> sp2((int *)malloc(sizeof(int) * 2), deletearrayfunc);
	return 0;
}
