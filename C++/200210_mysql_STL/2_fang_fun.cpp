#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class _mul_two
{
public:
	void operator()(int& data)
	{
		data <<= 1;
	}
};

class _mod_three
{
public:
	bool operator()(int data)
	{
		return data % 3 == 0;
	}
};

int main()
{
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	for_each(vec.begin(), vec.end(), _mul_two());
	for(auto e : vec)
	{
		cout<<e<<" ";
	}
	cout<<endl;
	auto pos = remove_if(vec.begin(), vec.end(), _mod_three());
	vec.erase(pos, vec.end());
	for_each(vec.begin(), vec.end(), [](int data){cout<<data<<" ";});
	cout<<endl;
	return 0;
}
