#include<iostream>
#include<deque>

using namespace std;

namespace mystd
{
	template<class T, class Con = deque<T>>
	class stack
	{
	public:
		stack()
		{}

		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			_c.pop_back();
		}

		T& top()
		{
			return _c.back();
		}

		const T& top() const
		{
			return _c.back();
		}

		size_t size() const
		{
			return _c.size();
		}

		bool empty() const
		{
			return _c.empty();
		}
	private:
		Con _c;
	};
}

int main()
{
	mystd::stack<int> s;
	for(size_t i = 0; i < 10; ++i)
	{
		s.push(i);
	}
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;
	cout<<s.top()<<endl;
	return 0;
}
