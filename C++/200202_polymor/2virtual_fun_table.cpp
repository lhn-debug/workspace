#include<iostream>

using namespace std;

class Base
{
public:
	virtual void fun1()
	{
		cout<<"Base::fun1()"<<endl;
	}

	virtual void fun2()
	{
		cout<<"Base::fun2()"<<endl;
	}
private:
	int _b = 1;
};

class Inher:public Base
{
public:
	virtual void fun1()
	{
		cout<<"Inher::fun1()"<<endl;
	}

	virtual void fun3()
	{
		cout<<"Inher::fun3()"<<endl;
	}

	virtual void fun4()
	{
		cout<<"Inher::fun4()"<<endl;
	}
private:
	int _i = 2;
};

typedef void(*VFPTR) ();

void PrintVTable(VFPTR vTable[])
{
	cout<<"Virtual Table Address > "<<vTable<<endl;
	for(int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("The %d Virtual Funcation Address : 0X%x, -> ", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout<<endl;
}

int main()
{
	Inher i;
	VFPTR * vTableI = (VFPTR *)(*(int *)&i);
	PrintVTable(vTableI);
	Base b;
	VFPTR * vTableB = (VFPTR *)(*(int *)&b);
	PrintVTable(vTableB);
	return 0;
}
