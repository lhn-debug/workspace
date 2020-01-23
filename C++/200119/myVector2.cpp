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

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}

		iterator begin() const
		{
			return _start;
		}

		iterator end() const
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
			T * tmp = new T[n];
			_start = tmp;
			_finish = _start + n;
			_endOfStorage = _start + n;
			for(size_t i = 0; i < n; i++)
			{
				_start[i] = value;
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			size_t sz = last - first;
			T * tmp = new T[sz];
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + sz;
			for(size_t i = 0; i < size(); ++i)
			{
				_start[i] = first[i];
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			reserve(v.capacity());
			auto it = begin();
			for(auto cit = v.cbegin(); cit != v.cend(); ++cit)
			{
				*it++ = *cit;
			}
			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}

		~vector()
		{
			if(_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}
		
		vector<T>& operator=(const vector<T>& v)
		{
			if(this != &v)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
				T * tmp = new T[v.capacity()];
				_start = tmp;
				for(size_t i = 0; i < v.size(); ++i)
				{
					_start[i] = v[i];
				}
				_finish = _start + v.size();
				_endOfStorage = _start + v.capacity();
			}
			return *this;
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
			size_t len = n - size();
			for(size_t i = 0; i < len; ++i)
			{
				push_back(value);
			}
		}

		void reserve(const size_t n)
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

		void push_back(const T& x)
		{
			if(_finish == _endOfStorage)
			{
				size_t oldSize = size();
				size_t newCapacity = (capacity() == 0) ? 1 : oldSize * 2;
				reserve(newCapacity);
			}
			iterator pos = _finish;
			*pos = x;
			++_finish;
		}

		void pop_back()
		{
			iterator it = end();
			erase(--it);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if(_finish == _endOfStorage)
			{
				size_t oldSize = size();
				size_t len = pos - _start;
				size_t newCapacity = (capacity() == 0) ? 1 : oldSize * 2;
				reserve(newCapacity);
				pos += len;
			}
			iterator it = _finish - 1;
			while(it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			for(iterator begin = pos + 1; begin != _finish; ++begin)
			{
				*(begin - 1) = *begin;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};
}

int main()
{
	char arr[] = {'s', 'd', 'g', 'h', 'e', 't', 'u', 'o'};
	mystd::vector<char> v(arr, arr + sizeof(arr)/sizeof(char));
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	v.resize(20, 'p');
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	v.reserve(30);
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	mystd::vector<char>::iterator pos = v.begin();
	pos += 3;
	v.insert(pos, 'a');
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	pos = v.begin();
	pos += 6;
	v.erase(pos);
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	v.push_back('q');
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	v.pop_back();
	for(auto x : v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	return 0;
}
