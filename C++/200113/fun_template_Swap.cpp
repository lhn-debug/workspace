#include<iostream>

using namespace std;

template<typename T>
void Swap(T& first, T& second)
{
	T tmp = first;
	first = second;
	second = tmp;
}

int main()
{
	int _ia = 1, _ib = 2;
	double _da = 1.2, _db = 2.3;
	char _ca = 'a', _cb = 'b';
	cout<<_ia<<" "<<_ib<<endl;
	cout<<_da<<" "<<_db<<endl;
	cout<<_ca<<" "<<_cb<<endl;
	Swap(_ia, _ib);
	Swap(_da, _db);
	Swap(_ca, _cb);
	cout<<_ia<<" "<<_ib<<endl;
	cout<<_da<<" "<<_db<<endl;
	cout<<_ca<<" "<<_cb<<endl;
	return 0;
}
