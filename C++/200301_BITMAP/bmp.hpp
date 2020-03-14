#pragma once

#include<vector>

class bmp
{
private:
	std::vector<int> _bit;
	size_t _bit_count;
public:
	bmp(size_t bit_count)
		:_bit((bit_count >> 5) + 1),_bit_count(bit_count)
	{}
//00000000000000000000000000100000
//bmp(32):_bit(2),_bit_count(32);
	void set(size_t which)
	{
//which=6:00000000...00000110
		if(which > _bit_count)
		{
//6>32?:return:next
			return;
		}
//index=6>>5=0
		size_t index = (which >> 5);
//pos=6%32=6
		size_t pos = (which % 32);
//_bit[0]=_bit[0]|(1<<6)=_bit[0]|64=64
		_bit[index] |= (1 << pos);
	}

	void reset(size_t which)
	{
		if(which > _bit_count)
		{
			return;
		}
		size_t index = (which >> 5);
		size_t pos = (which % 32);
//index=0;
//pos=6;
//_bit[0]=_bit[0]&~(1<<pos)=_bit[0]&11...11011111=0
		_bit[index] &= ~(1 << pos);
	}

	bool check(size_t which)
	{
		if(which > _bit_count)
		{
			return false;
		}
		size_t index = (which >> 5);
		size_t pos = (which % 32);
		return (_bit[index] & (1 << pos));
	}

	size_t size() const
	{
		return _bit_count;
	}
};
