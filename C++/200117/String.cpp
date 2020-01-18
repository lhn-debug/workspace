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

	bool operator<(const String& s)
	{
		if((*this) == s)
		{
			return false;
		}
		for(int i = 0; i < _size; ++i)
		{
			if(_str[i] < s._str[i])
			{
				return true;
			}
			else if(_str[i] > s._str[i])
			{
				return false;
			}
		}
		if(_size < s._size)
		{
			return true;
		}
	}

	bool operator<=(const String& s)
	{
		if(((*this) < s) || ((*this) == s))
		{
			return true;
		}
		return false;
	}

	bool operator>(const String& s)
	{
		if((*this) == s)
		{
			return false;
		}
		for(int i = 0; i < _size; ++i)
		{
			if(_str[i] > s._str[i])
			{
				return true;
			}
			else if(_str[i] < s._str[i])
			{
				return false;
			}
		}
		if(_size < s._size)
		{
			return false;
		}
	}

	bool operator>=(const String& s)
	{
		if(((*this) > s) || ((*this) == s))
		{
			return true;
		}
		return false;
	}
	
	bool operator==(const String& s)
	{
		if(s._size != _size)
		{
			return false;
		}
		for(int i = 0; i < _size; ++i)
		{
			if(s[i] != _str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const String& s)
	{
		if(s._size != _size)
		{
			return true;
		}
		for(int i = 0; i < _size; ++i)
		{
			if(s[i] != _str[i])
			{
				return true;
			}
		}
		return false;
		/*
		if((*this) == s)
		{
			return false;
		}
		return true;
		*/
	}

	size_t Find(char c, size_t pos = 0) const
	{
		for(int i = pos; i < _size; ++i)
		{
			if(c == _str[i])
			{
				return i;
			}
		}
		return -1;
	}

	size_t Find(const char * s, size_t pos = 0) const
	{
		for(int i = pos; i < _size; ++i)
		{
			int j = 0;
			for(j = 0; j < strlen(s); ++j)
			{
				if(s[j] != _str[i + j])
				{
					break;
				}
			}
			if(j == strlen(s))
			{
				return i;
			}
		}
		return -1;
	}

	String& Insert(size_t pos, char c)
	{
		if(_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size + 1] = '\0';
		for(int i = _size - 1; i >= pos; --i)
		{
			_str[i + 1] = _str[i];
		}
		_str[pos] = c;
		_size++;
		return *this;
	}

	String& Insert(size_t pos, const char * str)
	{
		for(int i = 0; i < strlen(str); ++i)
		{
			Insert(pos + i, str[i]);
		}
		return *this;
	}

	String& Erase(size_t pos, size_t len)
	{
		int index = pos;
		for(int i = pos + len; i < _size; ++i)
		{
			_str[pos++] = _str[i];
		}
		_str[pos] = '\0';
		_size -= len;
		return *this;
	}

private:
	friend ostream& operator<<(ostream& _cout, const String& s);

private:
	char * _str;
	size_t _capacity;
	size_t _size;
};

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout<<s._str<<" "<<s._size<<" "<<s._capacity;
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
	String s3("hello");
	String s4("linux");
	cout<<"s3==s4:"<<(s3==s4)<<endl;
	cout<<"s3!=s4:"<<(s3!=s4)<<endl;
	cout<<"s3<s4:"<<(s3<s4)<<endl;
	cout<<"s3<=s4:"<<(s3<=s4)<<endl;
	cout<<s4<<endl;
	cout<<s4.Find("nux")<<endl;
	s4.Insert(2, " hello code ");
	cout<<s4<<endl;
	s4.Erase(2, 12);
	cout<<s4<<endl;
	return 0;
}
