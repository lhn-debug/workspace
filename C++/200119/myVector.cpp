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

		vector();
		vector(int n, const T& value = T());

		template<class InputIterator>
		vector(InputIterator first, InputIterator last);

		vector(const vector<T>& v);

		~vector();

		vector<T>& operator=(const vector<T>& v);

		size_t size() const;
		size_t capacity() const;

		void reserve(size_t n);
		void resize(size_t n, const T& value = T());

		T& operator[](size_t pos);
		const T& operator[](size_t pos) const;

		void push_back(const T& x);
		void pop_back();

		void swap(vector<T>& v);

		iterator insert(iterator pos, const T& x);
		iterator erase(iterator pos);
	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};
}

int main()
{
	return 0;
}
