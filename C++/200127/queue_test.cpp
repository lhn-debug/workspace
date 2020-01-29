#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> q;
	for(size_t i = 0; i < 10; ++i)
	{
		q.push(i);
	}
	size_t len = q.size();
	while(len--)
	{
		cout<<q.front()<<endl;
		//cout<<q.back()<<endl;
		q.pop();
	}
	return 0;
}
