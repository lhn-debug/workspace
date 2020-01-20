#include<iostream>
#include<list>

using namespace std;

void PrintList(const list<int>& li)
{
	for(list<int>::const_iterator cit = li.begin(); cit != li.end(); ++cit)
	{
		cout<<*cit<<" ";
	}
	cout<<endl;
}

int main()
{	
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	list<int> li(arr, arr + sizeof(arr)/sizeof(int));
	
	//iterator
	for(list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	//reverse_iterator
	for(list<int>::reverse_iterator rit = li.rbegin(); rit != li.rend(); ++rit)
	{
		cout<<*rit<<" ";
	}
	cout<<endl;

	//const_iterator
	PrintList(li);
	return 0;
}
