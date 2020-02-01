#include<iostream>

using namespace std;

class Person
{
public:
	string _name;
};

class Student:public Person
{
protected:
	string _num;
};

class Teacher:public Person
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

	//ass._name = "a";二义性无法明确
	
	ass.Student::_name = "x";
	ass.Teacher::_name = "y";
	return 0;
}
