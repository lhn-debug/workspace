#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
class print
{
public:
	void operator()(const T& t)
	{
		cout<<t<<endl;
	}
};

int main()
{
	vector<int> v{34, 76, 43, 65, 87, 14, 63};
	for_each(v.begin(), v.end(), print<int>());
	return 0;
}
