#include<iostream>

using namespace std;

namespace mystd
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T * ptr = nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if(_ptr)
			{
				delete _ptr;
			}
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
		unique_ptr(unique_ptr<T> const &);
		unique_ptr<T>& operator=(unique_ptr<T> const &);
	private:
		T * _ptr;
	};
}

int main()
{
	int * tmp = new int();
	mystd::unique_ptr<int> up(tmp);
	*up = 10;
	cout<<*tmp<<endl;
	//mystd::unique_ptr<int> cp(up);防拷贝
	//mystd::unique_ptr<int> cp = up;防赋值
	return 0;
}
