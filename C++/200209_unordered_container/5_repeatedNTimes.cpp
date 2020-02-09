#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
	int repeatedNTimes(vector<int>& A)
	{
		int N = A.size()/2;
		unordered_multiset<int> ums;
		for(auto& e : A)
		{
			ums.insert(e);
		}
		for(auto& e : A)
		{
			if(ums.count(e) == N)
			{
				return e;
			}
		}
	}
};

int main()
{
	Solution sol;
	vector<int> A{1, 2, 3, 3, 3, 4};
	cout<<sol.repeatedNTimes(A)<<endl;
	return 0;
}
