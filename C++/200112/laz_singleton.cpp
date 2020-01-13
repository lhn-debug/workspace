#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

class Laz_Singleton
{
public:
	static Laz_Singleton * getInstance()
	{
		//Double-Check方式加锁，保证效率和线程安全
		if(nullptr == m_pInstance)
		{
			m_mtx.lock();
			if(nullptr == m_pInstance)
			{
				m_pInstance = new Laz_Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	//内嵌垃圾回收类
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if(Laz_Singleton::m_pInstance)
			{
				delete Laz_Singleton::m_pInstance;
			}
		}
	};
	//定义一个静态成员变量，程序结束时，系统会自动调用析构函数释放单例对象
	static CGarbo cgarbo;
private:
	Laz_Singleton(){}
	Laz_Singleton(Laz_Singleton const& laz_singleton){}
	Laz_Singleton& operator=(Laz_Singleton const& laz_singleton){}
	static Laz_Singleton * m_pInstance;//单例对象指针
	static mutex m_mtx;//互斥锁
};

Laz_Singleton * Laz_Singleton::m_pInstance = nullptr;
Laz_Singleton::CGarbo cgarbo;
mutex Laz_Singleton::m_mtx;

void func(int n)
{
	cout<<Laz_Singleton::getInstance()<<endl;
}

//多线程下加锁与不加锁的区别
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout<<Laz_Singleton::getInstance()<<endl;
	cout<<Laz_Singleton::getInstance()<<endl;
	return 0;
}
