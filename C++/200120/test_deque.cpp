#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

void PrintDeque(const deque<int>& de)
{
	for(const auto& e : de)
	{
		cout<<e<<" ";
	}
	cout<<endl;
}

int main()
{
	deque<int> d1;
	deque<int> d2(4, 100);
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);
	PrintDeque(d4);

	int arr[] = {12, 23, 56, 35, 47, 2, 46, 68, 45};
	deque<int> d(arr, arr + sizeof(arr)/sizeof(int));
	PrintDeque(d);
	
	for(auto it = d.crbegin(); it != d.crend(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	
	d.push_back(9);
	d.push_front(65);
	PrintDeque(d);
	cout<<d.size()<<endl;
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;

	d.insert(++d.begin(), 31);
	PrintDeque(d);

	d.pop_back();
	d.pop_front();
	d.erase(d.begin());
	PrintDeque(d);

	sort(d.begin(), d.end());
	//由于deque底层空间不连续，排序时需要多次遍历元素
	//计算空间位置，所以效率低
	PrintDeque(d);
	return 0;
}
