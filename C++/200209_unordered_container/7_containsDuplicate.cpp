#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_multiset<int> us;
		for(auto& e : nums)
		{
			us.insert(e);
		}
		for(int i = 0; i < us.bucket_count(); ++i)
		{
			if(us.bucket_size(i) > 1)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution sol;
	vector<int> v1{1, 2, 3, 3};
	vector<int> v2{1, 2, 3, 4};
	cout<<sol.containsDuplicate(v1)<<endl;
	cout<<sol.containsDuplicate(v2)<<endl;
	return 0;
}
