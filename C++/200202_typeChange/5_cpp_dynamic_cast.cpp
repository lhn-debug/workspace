#include<iostream>

using namespace std;

class Base
{
public:
	virtual void f(){}
};

class Inher:public Base
{};

void fun(Base * pb)
{
	Inher * pinher = dynamic_cast<Inher *>(pb);
	cout<<pinher<<endl;
}

int main()
{
	Base * pbase = new Base();
	fun(pbase);
	Inher * pinher = new Inher();
	fun(pinher);
	return 0;
}
