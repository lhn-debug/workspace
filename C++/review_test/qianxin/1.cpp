#include<iostream>
#include<vector>

using namespace std;

int fun(int n)
{
	if(n <= 4)
	{
		return 1;
	}
	return fun(n-1) + fun(n-4);
}

int main()
{
/*
	int n;
	vector<int> v;
	cin>>n;
	v.push_back(4);
	if(n <= 4)
	{
		cout<<v.size()<<endl;
		v.pop_back();
		return 0;
	}
	v.push_back(n);
	for(int i = 1; i <= n - 4; i++)
	{
		v.push_back(i);
	}
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i] > 4)
		{
			for(int i = 1; i <= n - 4; i++)
			{
				v.push_back(i);
			}
		}
	}
	cout<<v.size()<<endl;*/
	for(int i = 1; i < 100; i++)
	{
		cout<<fun(i)<<endl;
	}
	return 0;
}
