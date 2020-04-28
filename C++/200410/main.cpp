#include"student.hpp"
#include<iostream>

using namespace std;

void Student::display()
{
	cout<<_num<<endl;
	cout<<_name<<endl;
	cout<<_cls<<endl;
	cout<<_grade<<endl;
}

int main()
{
	Student s("1","fdfdf","fghf",23);
	s.display();
	return 0;
}
