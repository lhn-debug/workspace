#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<"["<<*it<<"]"<<":"<<&(*it)<<endl;
	}

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	cout<<*pos<<":"<<&(*pos)<<endl;
	v.erase(pos);
	cout<<*pos<<":"<<&(*pos)<<endl;

	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<"["<<*it<<"]"<<":"<<&(*it)<<endl;
	}

	pos = find(v.begin(), v.end(), 3);
	cout<<*pos<<":"<<&(*pos)<<endl;

	cout<<endl;

	int arr2[] = {1, 2, 3, 4, 5, 6};
	vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));

	for(vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		cout<<"["<<*it<<"]"<<":"<<&(*it)<<endl;
	}

	for(vector<int>::iterator it = v2.begin(); it != v2.end();)
	{
		if((*it) % 2 == 0)
		{
			it = v2.erase(it);
		}
		else
		{
			++it;
		}
	}

	for(vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		cout<<"["<<*it<<"]"<<":"<<&(*it)<<endl;
	}
	vector<int>::iterator pos2 = find(v2.begin(), v2.end(), 2);
	cout<<*pos2<<":"<<&(*pos2)<<endl;
	vector<int>::iterator pos3 = find(v2.begin(), v2.end(), 4);
	cout<<*pos3<<":"<<&(*pos3)<<endl;
	vector<int>::iterator pos4 = find(v2.begin(), v2.end(), 6);
	cout<<*pos4<<":"<<&(*pos4)<<endl;
	return 0;
}
