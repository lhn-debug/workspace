#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s;
	for(size_t i = 0; i < 10; ++i)
	{
		s.push(i);
	}
	size_t len = s.size();
	while(len--)
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
