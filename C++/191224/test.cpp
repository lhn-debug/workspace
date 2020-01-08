#include"head.h"

using namespace std;

/*--------------------extern--------------------*/

extern int i;
extern int fun(int);

int i=0;
int fun(int x)
{
	return x+i;
}

/*----------------------------------------------*/

extern string s;

int main()
{
//	cout<<fun(2)<<endl;	/*-----test extern-----*/
	
//	cout<<dec<<15<<endl;	/*-----十进制-----*/
//	cout<<oct<<15<<endl;	/*-----八进制-----*/
//	cout<<hex<<15<<endl;	/*-----十六进制-----*/
//	cout<<"non-printing char (escape):"<<char(27)<<endl;
	
/*
	int number;
	cin>>number;
	for(int i=0;i<10;i++)
	{
		sleep(1);
		cout<<(number++)<<endl;
	}
*/
	
/*	
	ifstream in("Scopy.cpp");
	string s;
	while(getline(in,s))
		cout<<s<<endl;
*/

/*
	ifstream in("Scopy.cpp");
	ofstream out("Scopy_back.cpp");
	string str,line;
	while(getline(in,line))
		str+=line+"\n";
	out<<str;
*/

/*
	vector<string> v;
	ifstream in("Scopy.cpp");
	string line;
	while(getline(in,line))
		v.push_back(line);
	for(int i=0;i<v.size();i++)
		cout<<i<<": "<<v[i]<<endl;
*/

	
	return 0;
}	
