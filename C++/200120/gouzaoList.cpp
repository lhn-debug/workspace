#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l1;
	list<int> l2(4, 100);
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l3);

	int arr[] = {1, 2, 3, 4, 5};
	list<int> l5(arr, arr + sizeof(arr)/sizeof(int));

	for(list<int>::iterator it = l5.begin(); it != l5.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	for(auto& x : l5)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}
