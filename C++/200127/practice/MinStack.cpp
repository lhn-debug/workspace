/*
 * 设计常数时间内检索到最小元素的栈
 * */

#include<iostream>
#include<stack>

using namespace std;

class MinStack
{
public:
	MinStack()
	{
		
	}

	void push(int x)
	{
		_elem.push(x);
		if(_min.empty() || _min.top() >= x)
		{
			_min.push(x);
		}
	}

	void pop()
	{
		if(_min.top() == _elem.top())
		{
			_min.pop();
		}
		_elem.pop();
	}

	int top()
	{
		return _elem.top();
	}

	int getMin()
	{
		return _min.top();
	}
private:
	stack<int> _elem;
	stack<int> _min;
};

int main()
{
	MinStack * ms = new MinStack();
	ms->push(6);
	ms->push(7);
	ms->push(5);
	ms->push(8);
	ms->push(4);
	ms->push(3);
	ms->push(9);
	cout<<ms->top()<<endl;
	cout<<ms->getMin()<<endl;
	ms->pop();
	ms->pop();
	cout<<ms->top()<<endl;
	cout<<ms->getMin()<<endl;
	return 0;
}
