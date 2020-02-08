/*
template<class T>
class singleton
{
public:
	static T _data;
public:
	static T * getInstance()
	{
		return &_data;
	}
};
*/

template<class T>
class singleton
{
public:
	volatile static T * _data;//volatile:防止编译器优化
	static std::mutex _lock;
public:
	static T * getInstance()
	{
		if(_data = nullptr)
		{
			_lock.lock();
			if(_data == nullptr)//双重判空，降低锁冲突效率，提高性能
			{
				_data = new T();
			}
			_lock.unlock();
		}
		return _data;
	}
};
