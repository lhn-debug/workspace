#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T * ptr = nullptr)
		:_ptr(ptr)
	{
		cout<<"SmartPtr(T)->"<<_ptr<<endl;
	}

	~SmartPtr()
	{
		if(_ptr)
		{
			cout<<"~SmartPtr()->"<<_ptr<<endl;
			delete _ptr;
		}
	}
private:
	T * _ptr;
};

int main()
{
	try
	{
		int * tmp = (int *)malloc(sizeof(int) * 10);
		SmartPtr<int> sp(tmp);
		vector<int> v(10, 5);
		v.at(10) = 20;
	}
	catch(const exception& e)
	{
		cout<<e.what()<<endl;
	}
	return 0;
}
