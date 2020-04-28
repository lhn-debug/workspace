#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
	private:
		string _num;
		string _name;
		string _cls;
		int _grade;
	public:
		Student(const string& num,const string& name,const string& cls,int grade)
			:_num(num),_name(name),_cls(cls),_grade(grade)
		{}
		void display();
};
