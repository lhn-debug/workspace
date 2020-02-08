#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
	vector<int> v{5, 3, 4, 2, 5, 3, 1, 4, 6, 6, 5, 8, 9, 0};
	multiset<int> ms(v.begin(), v.end());
	for(auto& e : ms)
	{
		cout<<e<<endl;
	}
	return 0;
}
