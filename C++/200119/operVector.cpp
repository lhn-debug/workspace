#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void testPushPop()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	for(int i = 8; i <= 12; ++i)
	{
		v.push_back(i);
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	v.pop_back();
	v.pop_back();
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void testFindInsertErase()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 4);
	v.insert(pos, 0);
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	pos = find(v.begin(), v.end(), 4);
	v.erase(pos);
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void testVisit()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
	
	for(int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	vector<int> tmp;
	tmp.swap(v);
	for(int i = 0; i < tmp.size(); ++i)
	{
		cout<<tmp[i]<<" ";
	}
	cout<<endl;

	for(auto x : tmp)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

int main()
{
	testPushPop();
	testFindInsertErase();
	testVisit();
	return 0;
}
