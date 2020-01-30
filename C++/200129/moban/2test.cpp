#include<iostream>
#include<cstring>

using namespace std;

template<class T1, class T2>
bool isEqual(T1& left, T2& right)
{
	return left == right;
}

template<>
bool isEqual<const char*>(const char* &left, const char* &right)
{
	return strcmp(left, right) == 0;
}

/*or
bool isEqual(const char* &left, const char* &right)
{
	return strcmp(left, right) == 0;
}
*/

int main()
{
	int a = 10;
	int b = 10;
	const char * p1 = "hello";
	const char * p2 = "hello";
	cout<<isEqual(a, b)<<endl;
	cout<<isEqual(p1, p2)<<endl;
	return 0;
}
