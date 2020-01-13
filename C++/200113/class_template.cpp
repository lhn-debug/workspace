#include<iostream>
#include<assert.h>

using namespace std;

template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[capacity]),
		_size(0),
		_capacity(capacity)
	{}
	~Vector();
	void PushBack(const T& data);
	void PopBack();
	size_t Size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}
private:
	T * _pData;
	size_t _size;
	size_t _capacity;
};

template<class T>//类模板函数在类外面定义时，需要加模板参数列表
Vector<T>::~Vector()
{
	if(_pData)
	{
		delete[] _pData;
	}
	_size = _capacity = 0;
}

int main()
{
	Vector<int> s1;
	Vector<double> s2;
	return 0;
}
