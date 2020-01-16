#include<iostream>

using namespace std;

void lastWordLength()
{
	string line;
	while(getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout<<line.size()-pos-1<<endl;
	}
}

int main()
{
	lastWordLength();
	return 0;
}
