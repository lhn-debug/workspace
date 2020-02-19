#pragma once

#include<string>
#include<vector>

vector<string> split_string(string str)
{
	vector<string> ret;
	string s;
	for(int i = 2; i < str.size(); i++)
	{
		if(str[i] == ' ')
		{
			ret.push_back(s);
			s.clear();
		}
		else
		{
			s += str[i];
			if(i == str.size() - 1)
			{
				ret.push_back(s);
			}
		}
	}
	return ret;
}

