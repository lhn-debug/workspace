#include<iostream>
#include<list>

using namespace std;

void PrintList(const list<int>& li)
{
	for(auto it = li.begin(); it != li.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	list<int> li{12, 23, 34, 45, 56, 67, 78};
	PrintList(li);

/*
 * 本段程序会崩溃
 * erase执行后，it所指节点已经被删除，导致it失效
 * 在下一次使用时，必须先赋值
	for(auto it = li.begin(); it != li.end(); ++it)
	{
		li.erase(it);
	}
*/

	for(auto it = li.begin(); it != li.end();)
	{
		it = li.erase(it);
	}

	PrintList(li);
	return 0;
}
