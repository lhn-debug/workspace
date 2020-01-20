#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;

void PrintList(const list<int>& li)
{
	for(auto x : li)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	list<int> li(arr, arr + sizeof(arr)/sizeof(int));
	PrintList(li);

	li.push_front(10);
	li.push_back(20);
	PrintList(li);

	li.pop_front();
	li.pop_back();
	PrintList(li);

/*
	list<int>::iterator pos = find(li.begin(), li.end(), 3);
	cout<<*pos<<endl;
*/

	auto pos = ++li.begin();
	cout<<*pos<<endl;

	li.insert(pos, 100);
	PrintList(li);

	li.insert(pos, 5, 200);
	PrintList(li);

	vector<int> v{300, 301, 302};
	li.insert(pos, v.begin(), v.end());
	PrintList(li);

	li.erase(pos);
	PrintList(li);

	list<int> tmp(li);

	li.erase(li.begin(), li.end());
	PrintList(li);

	PrintList(tmp);
	
	list<int> l{12, 23, 34, 45, 56};
	PrintList(l);
	PrintList(tmp);
	l.swap(tmp);
	PrintList(l);
	PrintList(tmp);

	cout<<l.size()<<endl;
	return 0;
}
