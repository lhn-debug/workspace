#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int>& v1, vector<int>& v2)
	{
		vector<int> ret;
		unordered_set<int> us1;
		for(auto& e : v1)
		{
			us1.insert(e);
		}
		unordered_set<int> us2;
		for(auto& e : v2)
		{
			us2.insert(e);
		}
		for(auto& e : us1)
		{
			if(us2.find(e) != us2.end())
			{
				ret.push_back(e);
			}
		}
		return ret;
	}
};

int main()
{
	Solution sol;
	vector<int> v1{1, 2, 2, 3, 3, 4, 5, 6, 6, 7};
	vector<int> v2{3, 3, 4, 7, 8, 9, 9, 0, 1, 1};
	vector<int> res = sol.intersection(v1, v2);
	for(auto& e : res)
	{
		cout<<e<<endl;
	}
	return 0;
}
