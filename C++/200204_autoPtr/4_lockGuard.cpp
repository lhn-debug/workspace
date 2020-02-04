#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

namespace mystd
{
	template<class Mutex>
	class lock_guard
	{
	public:
		lock_guard(Mutex& mtx)
			:_mutex(mtx)
		{
			_mutex.lock();
		}

		~lock_guard()
		{
			_mutex.unlock();
		}
	private:
		lock_guard(const lock_guard<Mutex>&) = delete;
		lock_guard<Mutex>& operator=(const lock_guard<Mutex>&) = delete;
	private:
		Mutex& _mutex;
	};
}

mutex _mtx;
static int n = 0;

void func()
{
	mystd::lock_guard<mutex> lock(_mtx);
	for(size_t i = 0; i < 1000000000; ++i)
	{
		++n;
	}
}

int main()
{
	int begin, end;
	begin = clock();
	thread t1(func);
	thread t2(func);
	t1.join();
	t2.join();
	end = clock();
	cout<<n<<endl;
	cout<<end - begin<<endl;
	return 0;
}
