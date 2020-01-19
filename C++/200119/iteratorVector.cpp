#include<iostream>
#include<vector>

using namespace std;

void PrintVector(const vector<int>& v)
{
	cout<<"const_iterator:";
	for(vector<int>::const_iterator cit = v.begin(); cit != v.end(); ++cit)
	{
		cout<<*cit<<" ";
	}
	cout<<endl;
}

int main()
{
	//构造空容器，插入数据
	vector<int> v;
	for(int i = 1; i < 10; ++i)
	{
		v.push_back(i);
	}

	//使用迭代器遍历打印
	cout<<"iterator:";
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	//使用迭代器修改
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		(*it) *= 2;
	}

	//使用反向迭代器遍历打印
	cout<<"reverse_iterator:";
	for(vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
	{
		cout<<*rit<<" ";
	}
	cout<<endl;
	
	//const对象使用const迭代器遍历打印
	PrintVector(v);

	return 0;
}
