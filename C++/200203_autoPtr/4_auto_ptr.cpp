#include<iostream>

using namespace std;

namespace mystd
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T * ptr = nullptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if(_ptr)
			{
				delete _ptr;
			}
		}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if(this != &ap)
			{
				if(_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T * _ptr;
	};
}

class Date
{
public:
	int _year;
};

int main()
{
	mystd::auto_ptr<Date> myap(new Date());
	myap->_year = 2020;
	cout<<myap->_year<<endl;
	mystd::auto_ptr<Date> cp(myap);
	//myap->_year = 2020;
	return 0;
}
