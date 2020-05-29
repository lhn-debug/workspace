#include<bits/stdc++.h>

using namespace std;

int main()
{
/*
	vector<int> vec;
	for(int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	auto pos = find(vec.begin(), vec.end(), 5);
	vec.erase(pos);
	cout<<*pos<<endl;

	pos = find(vec.begin(), vec.end(), 5);
	vec.insert(pos, 30);

	for(auto x : vec)
	{
		cout<<x<<endl;
	}
*/

	ofstream ofs("tt");
	ofs<<"asd"<<endl;
	ofs<<"bbb"<<endl;
	ofs<<"ccc"<<endl;
	ofs<<"ddd"<<endl;
	ofs<<"eee"<<endl;
	ofs.close();

	string tmp;
	ifstream ifs("tt");
	while(ifs>>tmp)
	{
		cout<<tmp<<endl;
	}
	ifs.close();
	return 0;
}
