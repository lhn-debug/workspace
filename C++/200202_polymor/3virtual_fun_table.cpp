#include<iostream>

using namespace std;

class Base1
{
public:
	virtual void fun1()
	{
		cout<<"Base1::fun1()"<<endl;
	}

	virtual void fun2()
	{
		cout<<"Base1::fun2()"<<endl;
	}
private:
	int _b1 = 1;
};

class Base2
{
public:
	virtual void fun1()
	{
		cout<<"Base2::fun1()"<<endl;
	}

	virtual void fun2()
	{
		cout<<"Base2::fun2()"<<endl;
	}
private:
	int _b2 = 1;
};

class Inher:public Base1,public Base2
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
	VFPTR * vTable1 = (VFPTR *)(*(int *)&i);
	PrintVTable(vTable1);

	Base1 b1;
	VFPTR * vTable2 = (VFPTR *)(*(int *)&b1);
	PrintVTable(vTable2);
	
	Base2 b2;
	VFPTR * vTable3 = (VFPTR *)(*(int *)&b2);
	PrintVTable(vTable3);
	return 0;
}
