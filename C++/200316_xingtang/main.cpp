#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<int> ret;
    int count = 0;
    for(int i = 0; i < s1.size(); i++)
    {
		if(s1[i] == s2[i] && i == s1.size() - 1)
		{
			ret.push_back(++count);
			break;
		}
        if(s1[i] == s2[i])
        {
            count++;
        }
        else
        {
            ret.push_back(count);
            count = 0;
        }
    }
	int max = ret[0];
    for(auto& e : ret)
    {
        if(e > max)
		{
			max = e;
		}
    }
	cout<<max<<endl;
    return 0;
}
