#include<initializer_list>
#include<iostream>

using namespace std;

template<class T>
class Vector
{
public:
	Vector(initializer_list<T> l):_capacity(l.size()),_size(0)
	{
		_array = new T[_capacity];
		for(auto e : l)
		{
			_array[_size++] = e;
		}
	}

	Vector<T>& operator=(initializer_list<T> l)
	{
		delete[] _array;
		_size = 0;
		_capacity = l.size();
		for(auto e : l)
		{
			_array[_size++] = e;
		}
		return *this;
	}
private:
	T * _array;
	size_t _capacity;
	size_t _size;
};

int main()
{
	Vector<int> v1{1, 2, 3};
	Vector<int> v2 = {1, 2};
	return 0;
}
