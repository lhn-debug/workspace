#include<iostream>
#include<set>

using namespace std;

int main()
{
	int arr[] = {2, 4, 2, 6, 7, 5, 2, 4, 6, 7, 8, 9, 0, 1};
	set<int> s(arr, arr + sizeof(arr)/sizeof(int));
	s.insert(12);
	s.insert(13);
	s.erase(13);
	s.erase(12);
	for(auto& e : s)
	{
		cout<<e<<endl;
	}
	cout<<endl;
	for(auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout<<*it<<endl;
	}
	return 0;
}
