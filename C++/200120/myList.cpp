#include<iostream>
#include<assert.h>

using namespace std;

namespace mystd
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			:_pPre(nullptr),
			_pNext(nullptr),
			_val(val)
		{}
		ListNode<T> * _pPre;
		ListNode<T> * _pNext;
		T _val;
	};

	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> * PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}

		ListIterator(const Self& l)
			:_pNode(l._pNode)
		{}

		T& operator*()
		{}

		T& operator->()
		{}

		Self& operator++()
		{}

		Self operator++(int)
		{}

		Self& operator--()
		{}

		Self operator--(int)
		{}

		bool operator!=(const Self& l)
		{}

		bool operator==(const Self& l)
		{}
	
		PNode _pNode;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		list()
		{}

		list(int n, const T& value = T())
		{}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{}

		list(const list<T>& l)
		{}

		list<T>& operator=(const list<T> l)
		{}

		~list()
		{}

		iterator begin()
		{}

		iterator end()
		{}

		const_iterator begin()
		{}

		const_iterator end()
		{}

		size_t size() const
		{}

		size_t empty() const
		{}

		T& front()
		{}

		const T& front() const
		{}

		T& back()
		{}

		const T& back() const
		{}

		void push_back(const T& val)
		{}

		void pop_back()
		{}

		void push_front(const T& val)
		{}

		void pop_front()
		{}

		iterator insert(iterator pos, const T& val)
		{}

		iterator erase(iterator pos)
		{}

		void clear()
		{}

		void swap(list<T>& l)
		{}
	private:
		void createHead()
		{}
	private:
		PNode _pHead;
	};
}

int main()
{
	return 0;
}
