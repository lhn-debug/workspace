#include<iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>

using namespace std;

class String
{
public:
	typedef char * iterator;

public:
	String(const char * str = "")
	{
		if(str == nullptr)
		{
			str = "";
		}
		_size = strlen(str);
		_capacity = 10;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_size(s._size),
		_capacity(s._capacity),
		_str(new char[_capacity + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			delete[] _str;
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}

	~String()
	{
		if(_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	void PushBack(char c)
	{
		if(_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size] = c;
		_str[++_size] = '\0';
	}

	String& operator+=(char c)
	{
		PushBack(c);
		return *this;
	}

	void Append(const char * str)
	{
		for(int i = 0; i < strlen(str); ++i)
		{
			PushBack(str[i]);
		}
	}

	String& operator+=(const char * str)
	{
		Append(str);
		return *this;
	}

	void Clear()
	{
		strcpy(_str, "");
		_size = strlen(_str);
		_capacity = 10;
		_str = new char[_capacity + 1];
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	const char * C_str() const
	{
		return _str;
	}
	
	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	bool Empty() const
	{
		if(_size == 0)
		{
			return 1;
		}
		return 0;
	}

	void Resize(size_t newSize, char c = '\0')
	{
		if(newSize > _size)
		{
			if(newSize > _capacity)
			{
				Reserve(newSize);
			}
			memset(_str + _size, c, newSize - _size);
		}
		_size = newSize;
		_str[newSize] = '\0';
	}

	void Reserve(size_t newCapacity)
	{
		if(newCapacity > _capacity)
		{
			char * tmp = new char[newCapacity + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = newCapacity;
		}
	}

	char& operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}

	const char& operator[](size_t index) const
	{
		assert(index < _size);
		return _str[index];
	}

	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	size_t Find(char c, size_t pos = 0) const;
	size_t Find(const char * s, size_t pos = 0) const;
	String& Insert(size_t pos, char c);
	String& Insert(size_t pos, const char * str);
	String& Erase(size_t pos, size_t len);

private:
	friend ostream& operator<<(ostream& _cout, const String& s);

private:
	char * _str;
	size_t _capacity;
	size_t _size;
};

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout<<s._str<<" "<<s._size<<" "<<s._capacity<<endl;
	return _cout;
}

int main()
{
	String s1("hello");
	cout<<s1<<endl;
	cout<<s1.Size()<<endl;
	cout<<s1.Capacity()<<endl;
	cout<<s1.Empty()<<endl;
	s1.PushBack('c');
	cout<<s1<<endl;
	s1 += 'c';
	cout<<s1<<endl;
	s1.Append("linux");
	cout<<s1<<endl;
	s1 += "code";
	cout<<s1<<endl;
	s1.Clear();
	cout<<s1<<endl;
	s1.Append("linux");
	cout<<s1<<endl;
	String s2;
	cout<<s2<<endl;
	s2.Append("linuxcode");
	cout<<s2<<endl;
	s1.Swap(s2);
	cout<<s1<<endl;
	cout<<s1.C_str()<<endl;
	cout<<s2<<endl;
	s2.Resize(20);
	cout<<s2<<endl;
	cout<<s2[2]<<endl;
	return 0;
}
