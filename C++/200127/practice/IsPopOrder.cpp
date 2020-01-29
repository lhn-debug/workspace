#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution
{
public:
	static bool IsPopOrder(vector<int> PushV, vector<int> PopV)
	{
		if(PushV.size() != PopV.size())
		{
			return false;
		}
		stack<int> s;
		size_t pushSize = 0;
		size_t popSize = 0;
		while(popSize < PopV.size())
		{
			while(s.empty() || s.top() != PopV[popSize])
			{
				if(pushSize < PushV.size())
				{
					s.push(PushV[pushSize++]);
				}
				else
				{
					return false;
				}
			}
			s.pop();
			popSize++;
		}
		return true;
	}
};

int main()
{
	vector<int> pushV{1, 2, 3, 4, 5};
	vector<int> popV{4, 5, 3, 1, 2};
	cout<<Solution::IsPopOrder(pushV, popV)<<endl;
	return 0;
}

