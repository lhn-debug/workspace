#include<iostream>

using namespace std;

namespace mystd
{
	template<class T, size_t N = 10>
	class array
	{
	public:
		array():_size(N)
		{}

		T& operator[](size_t index)
		{
			return _array[index];
		}

		const T& operator[](size_t index) const
		{
			return _array[index];
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			return (_size == 0);
		}
	private:
		T _array[N];
		size_t _size;
	};
}

int main()
{
	mystd::array<int, 10> arr;
	for(size_t i = 0; i < arr.size(); ++i)
	{
		arr[i] = i;
	}
	for(size_t i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
