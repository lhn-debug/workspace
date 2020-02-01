#include<iostream>

using namespace std;

class Person
{
public:
	string _name;
};

class Student:virtual public Person
{
protected:
	string _num;
};

class Teacher:virtual public Person
{
protected:
	string _id;
};

class Assistant:public Student,public Teacher
{
protected:
	string _majorCourse;
};

int main()
{
	Assistant ass;
	ass._name = "a";
	return 0;
}
