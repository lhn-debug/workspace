#include<iostream>
#include<cstring>

using namespace std;

//size/length/capacity/clear/resize
void test_string_1()
{
	string s("hello");
	cout<<s<<endl;//hello
	cout<<s.size()<<endl;//5
	cout<<s.length()<<endl;//5
	cout<<s.capacity()<<endl;//15

	s.clear();
	cout<<s<<endl;//
	cout<<s.size()<<endl;//0
	cout<<s.capacity()<<endl;//15

	s.resize(10, 'a');
	cout<<s<<endl;//aaaaaaaaaa
	cout<<s.size()<<endl;//10
	cout<<s.capacity()<<endl;//15

	s.resize(15);
	cout<<s<<endl;//aaaaaaaaaa\0\0\0\0\0
	cout<<s.size()<<endl;//15
	cout<<s.capacity()<<endl;//15

	s.resize(5);
	cout<<s<<endl;//aaaaa
	cout<<s.size()<<endl;//5
	cout<<s.capacity()<<endl;//15
}

//reserve
void test_string_2()
{
	string s;
	s.reserve(100);
	cout<<s.size()<<endl;//0
	cout<<s.capacity()<<endl;//100

	s.reserve(50);
	cout<<s.size()<<endl;//0
	cout<<s.capacity()<<endl;//50
}

//用reserve提高插入效率，避免增容带来的开销
//有开销
void test_pushBack()
{
	string s;
	size_t sz = s.capacity();
	for(int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if(sz != s.capacity())
		{
			sz = s.capacity();
			cout<<sz<<endl;
		}
	}
	cout<<s<<endl;
}

//无开销
void test_pushBack_reserve()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	for(int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if(sz != s.capacity())
		{
			sz = s.capacity();
			cout<<sz<<endl;
		}
	}
	cout<<s<<endl;
}

int main()
{
	test_string_1();
	cout<<endl;
	test_string_2();
	cout<<endl;
	test_pushBack();
	cout<<endl;
	test_pushBack_reserve();
	return 0;
}
