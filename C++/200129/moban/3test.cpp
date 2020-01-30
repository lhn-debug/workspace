#include<iostream>

using namespace std;

template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout<<"<T1, T2>"<<endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout<<"<T1, int>"<<endl;
	}
	T1 _d1;
	int _d2;
};

int main()
{
	Data<char, char> d1;
	Data<char, int> d2;
	return 0;
}
