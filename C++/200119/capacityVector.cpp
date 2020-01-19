#include<iostream>
#include<vector>

using namespace std;

void testCapacity()
{
	vector<int> v;
	size_t sz = v.capacity();
	for(int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if(sz != v.capacity())
		{
			sz = v.capacity();
			cout<<"[testCapacity]capacity changed:"<<sz<<endl;
		}
	}
}

void testReserve()
{
	vector<int> v;
	size_t sz = v.capacity();
	v.reserve(100);
	for(int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if(sz != v.capacity())
		{
			sz = v.capacity();
			cout<<"[testReserve]capacity changed:"<<sz<<endl;
		}
	}
}

void testResize()
{
	vector<int> v;
	for(int i = 1; i < 10; ++i)
	{
		v.push_back(i);
	}
	cout<<"[testResize]size channged:"<<v.size()<<endl;
	v.resize(5);
	cout<<"[testResize]size channged:"<<v.size()<<endl;
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	v.resize(8, 100);
	cout<<"[testResize]size channged:"<<v.size()<<endl;
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	v.resize(12);
	cout<<"[testResize]size channged:"<<v.size()<<endl;
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	testCapacity();
	testReserve();
	testResize();
	return 0;
}
