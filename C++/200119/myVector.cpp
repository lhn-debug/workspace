#include<iostream>
#include<assert.h>

using namespace std;

namespace mystd
{
	template<class T>
	class vector
	{
	public:
		typedef T * iterator;
		typedef const T * const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{}

		vector(int n, const T& value = T())
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			reserve(n);
			while(n--)
			{
				push_back(value);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while(first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator cit = v.cbegin();
			while(cit != v.cend())
			{
				*it++ = *cit++;
			}
			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}

		~vector()
		{
			if(_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage;
			}
		}

		vector<T>& operator=(const vector<T>& v)
		{
			swap(v);
			return *this;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		void reserve(size_t n)
		{
			if(n > capacity())
			{
				size_t oldSize = size();
				T * tmp = new T[n];
				if(_start)
				{
					for(size_t i = 0; i < oldSize; ++i)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + oldSize;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if(n <= size())
			{
				_finish = _start + n;
				return;
			}
			if(n > capacity())
			{
				reserve(n);
			}
			iterator it = _finish;
			iterator _finish = _start + n;
			while(it != _finish)
			{
				*it = value;
				++it;
			}
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}

		void push_back(const T& x)
		{
			insert(end(), x);	
		}

		void pop_back()
		{
			erase(--end());
		}

		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if(_finish == _endOfStorage)
			{
				size_t sz = size();
				size_t newCapacity = (capacity() == 0) ? 1 : capacity() * 2;
				reserve(newCapacity);
				pos = _start + sz;
			}
			iterator end = _finish - 1;
			while(end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			for(iterator begin = pos + 1; begin != _finish; begin++)
			{
				*(begin - 1) = *begin;
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start;//指向数据块开始
		iterator _finish;//指向有效数据的尾
		iterator _endOfStorage;//指向存储容量的尾
	};
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	mystd::vector<int> v1(arr, arr + sizeof(arr)/sizeof(int));
	cout<<v1.size()<<endl;
	cout<<v1.capacity()<<endl;
	return 0;
}
