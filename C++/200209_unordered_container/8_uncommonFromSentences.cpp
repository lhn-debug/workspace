#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
	vector<string> uncommonFromSentences(string A, string B)
	{
		vector<string> ret;
		unordered_multiset<string> umsa;
		unordered_multiset<string> umsb;
		vector<string> va = splitStringToWords(A);
		vector<string> vb = splitStringToWords(B);
		for(auto& e : va)
		{
			umsa.insert(e);
		}
		for(auto& e : vb)
		{
			umsb.insert(e);
		}
		for(auto& e : umsa)
		{
			if(umsa.count(e) == 1 && umsb.count(e) == 0)
			{
				ret.push_back(e);
			}
		}
		for(auto& e : umsb)
		{
			if(umsb.count(e) == 1 && umsa.count(e) == 0)
			{
				ret.push_back(e);
			}
		}
		return ret;
	}
private:
	vector<string> splitStringToWords(string str)
	{
		vector<string> ret;
		string s;
		for(int i = 0; i < str.size(); ++i)
		{
			if(str[i] == ' ')
			{
				ret.push_back(s);
				s.clear();
			}
			else
			{
				s += str[i];
				if(i == (str.size() - 1))
				{
					ret.push_back(s);
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution sol;
	string A("this apple is sweet");
	string B("this apple is sour");
	vector<string> res = sol.uncommonFromSentences(A, B);
	for(auto& e : res)
	{
		cout<<e<<endl;
	}
	return 0;
}
