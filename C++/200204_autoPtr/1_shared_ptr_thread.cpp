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
			:_pRefCount(new int(1)),
			_ptr(ptr),
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
			_pMutex->lock();
			++(*_pRefCount);
			_pMutex->unlock();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if(this != &sp)
			{
				Release();
				_ptr = sp._ptr;
				_pRefCount = sp._pRefCount;
				_pMutex = sp._pMutex;
				_pMutex->lock();
				++(*_pRefCount);
				_pMutex->unlock();
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
			bool mutexflag = false;
			_pMutex->lock();
			if(--(*_pRefCount) == 0)
			{
				delete _pRefCount;
				delete _ptr;
				mutexflag = true;
			}
			_pMutex->unlock();
			if(mutexflag)
			{
				delete _pMutex;
			}
		}
	private:
		int * _pRefCount;
		T * _ptr;
		mutex * _pMutex;
	};
}

struct Date
{
	int _year = 2020;
	int _month = 1;
	int _day = 1;
};

void func(mystd::shared_ptr<Date> sp)
{
	cout<<sp.get()<<endl;
	mystd::shared_ptr<Date> cp(sp);
	cp->_year++;
	cp->_month++;
	cp->_day++;
}

int main()
{
	Date * date = new Date();
	mystd::shared_ptr<Date> sp(date);
	cout<<sp.get()<<endl;
	thread t1(func, sp);
	thread t2(func, sp);
	t1.join();
	t2.join();
	cout<<sp->_year<<endl;
	cout<<sp->_month<<endl;
	cout<<sp->_day<<endl;
	return 0;
}
