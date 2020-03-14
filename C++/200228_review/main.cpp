#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string str;
	cin>>str;
	stack<char> st;
	for(int i = 0; i < str.size(); i++)
	{
		if((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
		{
			st.push(str[i]);
		}
		else if((str[i] == ')' && st.top() == '(') 
			|| (str[i] == ']' && st.top() == '[') 
			|| (str[i] == '}' && st.top() == '{'))
		{
			st.pop();
		}
		else
		{
			break;
		}
	}
	if(st.empty())
	{
		cout<<"T"<<endl;
	}
	else
	{
		cout<<"F"<<endl;
	}
	return 0;
}
