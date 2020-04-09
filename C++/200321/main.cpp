#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>

using namespace std;

bool is_huiwen(int num)
{
	char ch[64];
	sprintf(ch, "%d", num);
	string str(ch);
	int begin = 0;
	int end = str.size() - 1;
	bool ret = true;
	while(begin < end)
	{
		if(str[begin] != str[end])
		{
			ret = false;
			break;
		}
		else
		{
			begin++;
			end--;
		}
	}
	return ret;
}

bool is_sushu(int num)
{
	bool ret = true;
	for(int i = 2; i <= sqrt(num); i++)
	{
		if(num % i == 0)
		{
			ret = false;
			break;
		}
	}
	return ret;
}

int main()
{
	int begin_num, end_num;
	cin>>begin_num>>end_num;
	int count = 0;
	for(int i = begin_num; i <= end_num; i++)
	{
		bool flag = is_huiwen(i);
		if(flag)
		{
			bool tag = is_sushu(i);
			if(tag)
			{
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
