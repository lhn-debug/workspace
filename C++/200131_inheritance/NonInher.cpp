#include<iostream>

using namespace std;

class NonInher
{
public:
	static NonInher GetInstance()
	{
		return NonInher();
	}
private:
	NonInher()
	{}
};

/*C++11:final关键字禁止继承
class NonInher final
{};
*/

/*
class Test:public NonInher
{};
*/

int main()
{
	return 0;
}
