/*
 * buffer.cpp
 */

#include"../include/myinclude.hpp"
	
Buffer::Buffer()
{
	disk.open(DISK, std::fstream::in | std::fstream::out | std::fstream::binary);
	if(disk.is_open())
	{
		cout<<"file open......"<<endl;
	}
	else
	{
		cout<<"file not open......"<<endl;
	}
}

Buffer::~Buffer()
{
	disk.close();
}

bool Buffer::write_disk(const BufferNode& node)
{
	assert(node.sec_num >= 0 && node.sec_num < MAX_SEC);

	int i;
	
	i= has_sec(node.sec_num);

	if(i >= 0)
	{
		cout<<"write disk：buffer has this sector......"<<endl;
		cache[i].update(node);
		return true;
	}

	i = is_full();

	if(i >= 0)
	{
		cout<<"write disk：buffer full，replace number  "<<i<<" buffer......"<<endl;
		real_disk_write(cache[i]);
		cache.erase(cache.begin() + i);
	}

	cache.push_back(node);
	cout<<"write disk：data has written buffer......"<<endl;
	return true;
}

bool Buffer::read_disk(int sec_num, BufferNode& node)
{
	assert(sec_num >= 0 && sec_num < MAX_SEC);

	int i;

	i = has_sec(sec_num);

	if(i >= 0)
	{
		cout<<"read disk：buffer has this sector......"<<endl;
		node.update(cache[i]);
		return true;
	}

	i = is_full();

	if(i >= 0)
	{
		cout<<"read disk：buffer full，replace number  "<<i<<" buffer......"<<endl;
		real_disk_write(cache[i]);
		cache.erase(cache.begin() + i);
		real_disk_read(sec_num, node);
		node.init(sec_num);
		cache.push_back(node);
	}
	else
	{
		real_disk_read(sec_num, node);
		node.init(sec_num);
		cache.push_back(node);
		cout<<"read disk：data has written buffer......"<<endl;
	}

	return true;
}

bool Buffer::real_disk_write(const BufferNode& node)
{
	assert(node.sec_num >= 0 && node.sec_num < MAX_SEC);

	cout<<"real disk write:write into number "<<node.sec_num<<" sector"<<endl;
	disk.seekg(node.sec_num * SEC_SIZE, disk.beg);
	disk.write(node.buffer, SEC_SIZE);

	return true;
}

bool Buffer::real_disk_read(int sec_num, BufferNode& node)
{
	assert(sec_num >= 0 && sec_num < MAX_SEC);

	cout<<"real disk read:read number "<<sec_num<<" sector"<<endl;
	disk.seekg(sec_num * SEC_SIZE, disk.beg);
	disk.read(node.buffer, SEC_SIZE);
	node.buffer[SEC_SIZE] = '\0';
	node.sec_num = sec_num;

	return true;
}

int Buffer::has_sec(int sec_number)
{
	for(int i = 0; i < cache.size(); i++)
	{
		if(cache[i].sec_num == sec_number)
		{
			return i;
		}
	}
	return -1;
}

int Buffer::is_full()
{
	if(cache.size() == 15)
	{
		int min = 9999, min_i = 0;
		for(int i = 0; i < cache.size(); i++)
		{
			if(cache[i].pri < min)
			{
				min = cache[i].pri;
				min_i = i;
			}
		}
		return min_i;
	}
	else
	{
		return -1;
	}
}
