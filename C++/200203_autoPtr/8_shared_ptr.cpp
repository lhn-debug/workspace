#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

namespace mystd
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T * ptr = nullptr)
			:_ptr(ptr),
			_pRefCount(new int(1)),
			_pMutex(new mutex())
		{}

		~shared_ptr()
		{
			cout<<"~shared_ptr()"<<endl;
			Release();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr),
			_pRefCount(sp._pRefCount),
			_pMutex(sp._pMutex)
		{
			AddRefCount();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if(this != &sp)
			if(_ptr != sp._ptr)
			{
				Release();
				_ptr = sp._ptr;
				_pRefCount = sp._pRefCount;
				_pMutex = sp._pMutex;
				AddRefCount();
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

		int useCount()
		{
			return *_pRefCount;
		}

		T* get()
		{
			return _ptr;
		}
	private:
		void Release()
		{
			bool deletetag = false;
			_pMutex->lock();
			if(--(*_pRefCount) == 0)
			{
				delete _ptr;
				delete _pRefCount;
				deletetag = true;
			}
			_pMutex->unlock();
			if(deletetag)
			{
				delete _pMutex;
			}
		}

		void AddRefCount()
		{
			_pMutex->lock();
			++(*_pRefCount);
			_pMutex->unlock();
		}
	private:
		int * _pRefCount;
		T * _ptr;
		mutex * _pMutex;
	};
}

int main()
{
	mystd::shared_ptr<int> sp1(new int(10));
	mystd::shared_ptr<int> sp2(sp1);
	mystd::shared_ptr<int> sp3 = sp2;
	*sp2 = 20;
	*sp3 = 30;
	cout<<*sp1<<" "<<*sp2<<" "<<*sp3<<endl;
	cout<<sp1.get()<<" "<<sp1.useCount()<<endl;
	cout<<sp2.get()<<" "<<sp2.useCount()<<endl;
	cout<<sp3.get()<<" "<<sp3.useCount()<<endl;
	return 0;
}
