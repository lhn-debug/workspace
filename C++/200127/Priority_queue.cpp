#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

namespace mystd
{
	template<class T, class Sequence = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue():c()
		{}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:c(first, last)
		{
			make_heap(c.begin(), c.end(), comp);
		}

		void push(const T& x)
		{
			c.push_back(x);
			push_heap(c.begin(), c.end(), comp);
		}

		void pop()
		{
			pop_heap(c.begin(), c.end(), comp);
			c.pop_back();
		}

		T& top()
		{
			return c.front();
		}

		const T& top() const
		{
			return c.front();
		}

		size_t size() const
		{
			return c.size();
		}

		bool empty() const
		{
			return c.empty();
		}
	private:
		Sequence c;
		Compare comp;
	};
}

int main()
{
	mystd::priority_queue<int> pq;
	pq.push(12);
	pq.push(34);
	pq.push(20);
	pq.push(56);
	pq.push(10);
	cout<<pq.top()<<endl;
	cout<<pq.size()<<endl;
	cout<<pq.empty()<<endl;
	pq.pop();
	pq.pop();
	cout<<pq.top()<<endl;
	cout<<pq.size()<<endl;
	cout<<pq.empty()<<endl;
	
	const int arr[] = {12, 34, 20, 56, 10};
	mystd::priority_queue<int> p(arr, arr + sizeof(arr)/sizeof(int));
	cout<<p.top()<<endl;
	cout<<p.size()<<endl;
	cout<<p.empty()<<endl;
	p.pop();
	p.pop();
	cout<<p.top()<<endl;
	cout<<p.size()<<endl;
	cout<<p.empty()<<endl;
	return 0;
}
