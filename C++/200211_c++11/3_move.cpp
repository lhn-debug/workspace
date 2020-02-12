#include<iostream>
#include<string>

using namespace std;

class person
{	
private:
	string _name;
	string _sex;
	size_t _age;
public:
	person() = default;
	person(char *name, char *sex, size_t age)
		:_name(name),_sex(sex),_age(age)
	{}
	person(const person& p)
		:_name(p._name),_sex(p._sex),_age(p._age)
	{}
#if 0
	person(person&& p)
		:_name(p._name),_sex(p._sex),_age(p._age)
	{}
#else
	person(person&& p)
		:_name(move(p._name)),_sex(move(p._sex)),_age(p._age)
	{}
#endif
};

person getInstance()
{
	//person p("1", "1", 22);
	person p;
	return p;
}

int main()
{
	person p(getInstance());
	return 0;
}
