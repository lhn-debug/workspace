#include<iostream>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int> pq;
	pq.push(23);
	pq.push(98);
	pq.push(56);
	pq.push(14);
	pq.push(33);
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	return 0;
}
