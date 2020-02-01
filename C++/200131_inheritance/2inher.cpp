#include<iostream>

using namespace std;

class Person
{
protected:
	string _name;
	string _sex;
	int _age;
};

class Student:public Person
{
public:
	int _no;
};

int main()
{
	Student sobj;

	//子类对象赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* ppobj = &sobj;
	Person& rpobj = sobj;

	//sobj = pobj;基类对象不能赋值给派生类对象

	//基类的指针可以通过强制类型装换赋值给派生类指针
	ppobj = &sobj;
	Student* psobj1 = (Student *)ppobj;
	psobj1->_no = 123;

	//有时可能会出现越界访问
	ppobj = &pobj;
	Student* psobj2 = (Student *)ppobj;
	psobj2->_no = 234;
	return 0;
}
