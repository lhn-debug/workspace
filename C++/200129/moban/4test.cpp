#include<iostream>

using namespace std;

/*基础模板*/
template<typename T1, typename T2>
class Data
{
public:
	Data()
	{
		cout<<"<T1, T2>"<<endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

/*全特化模板*/
template<>
class Data<char *, char *>
{
public:
	Data()
	{
		cout<<"<char*, char*>"<<endl;
	}
private:
	char* _d1;
	char* _d2;
};

/*偏特化-部分特化模板*/
template<typename T>
class Data<T, char*>
{
public:
	Data()
	{
		cout<<"<T, char*>"<<endl;
	}
private:
	T _d1;
	char* _d2;
};

/*偏特化-参数进一步的限制-两个参数偏特化为指针引用类型*/
template<typename T1, typename T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout<<"<T1*, T2*>"<<endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<typename T1, typename T2>
class Data<T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1), _d2(d2)
	{
		cout<<"<T1&, T2&>"<<endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()
{
	Data<int, int> d1;
	Data<char*, char*> d2;
	Data<int, char*> d3;
	Data<int*, int*> d4;
	Data<int&, int&> d5(1, 2);
	return 0;
}
