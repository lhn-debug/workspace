#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
	string str, out;
	getline(cin, str);
	stack<int> st;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= 48 && str[i] <= 57)
		{
			st.push(str[i]);
		}
		else if(st.empty())
		{
			string tmp;
			for(int j = 0; j < out.size(); j++)
			{
				tmp += out[j];
				if(out[j] == ')' && out[j + 1] == '(')
				{
					tmp += str[i];
				}
			}
			out.clear();
			out = tmp;
			tmp.clear();
		}
		else
		{
			char ch[2];
			ch[1] = st.top();
			st.pop();
            if(st.empty())
            {
                out = out + ch[1] + str[i];
            }
			else
            {
                ch[0] = st.top();
			    st.pop();
			    out = out + '(' + ch[0] + str[i] + ch[1] + ')';
            }
		}
	}
	cout<<out<<endl;
	return 0;
}
