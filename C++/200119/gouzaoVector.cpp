#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> first;//int型空vector
	vector<int> second(4, 100);//int型4个100的vector
	vector<int> third(second.begin(), second.end());//通过迭代器构造
	vector<int> fourth(third);//拷贝构造

	//迭代器初始化构造vector
	int myints[] = {1, 2, 3, 4};
	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	for(vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
