/*
 * myinclude.hpp
 */

#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<assert.h>

#define SEC_SIZE 512
#define INODE_NUM 131072
#define BLOCK_NUM 131072
#define DISK "disk.img"
#define SUPER_BEGIN 0
#define INODE_BEGIN sizeof(superblock)
#define BLOCK_BEGIN (sizeof(superblock) + sizeof(Inode) * INODE_NUM)
#define MAX_SEC ((BLOCK_BEGIN + BLOCK_NUM * SEC_SIZE) / SEC_SIZE)

using namespace std;

class superblock
{
private:
	bool inode_bitmap[INODE_NUM];
	bool block_bitmap[BLOCK_NUM];

public:
	superblock();

	int remain_inode();
	int remain_sec();
	int get_new_inode();
	int get_new_sec();
	bool recv_inode(int inode_num);
	bool recv_sec(int sec_num);
	bool init();
};

struct BufferNode
{
	char buffer[SEC_SIZE + 1];
	int pri;
	int sec_num;

	BufferNode operator=(const BufferNode& bn)
	{
		memcpy(buffer, bn.buffer, SEC_SIZE + 1);
		pri = bn.pri;
		sec_num = bn.sec_num;
	}

	BufferNode()
	{
		memset(buffer, 0, SEC_SIZE);
		pri = 0;
		sec_num = 0;
	}

	void init(int _sec_num)
	{
		pri = 5;
		sec_num = _sec_num;
	}

	void update(const BufferNode& bn)
	{
		memcpy(buffer, bn.buffer, SEC_SIZE + 1);
		pri = bn.pri + 1;
		sec_num = bn.sec_num;
	}
};

class Buffer
{
private:
	vector<BufferNode> cache;
	fstream disk;

public:
	Buffer();
	~Buffer();
	bool write_disk(const BufferNode& node);
	bool read_disk(int sec_num, BufferNode& node);

private:
	bool real_disk_write(const BufferNode& node);
	bool real_disk_read(int sec_num, BufferNode& node);
	int has_sec(int sec_number);
	int is_full();
};

class Inode
{
private:
	int _inode_num;
	bool _is_file;
	int _file_size;
	int _sec_beg;
	int _sec_num;
	char _compensate[12];

public:
	Inode();
	Inode(int node_num, bool is_file, int file_size, int sec_begin);
	int get_inode_num();
	bool get_type();
	int get_file_size();
	int get_sec_beg();
	int get_sec_num();
	void set_inode_num(int num);
	int get_inode_sec_num();
	bool read_inode_from_disk(int inode_num, Buffer& buffer);
	bool write_inode_back_to_disk(Buffer& buffer);
};

struct sector_dir_entry
{
	char name[28];
	int inode_num;
	
	sector_dir_entry();
	sector_dir_entry operator=(const sector_dir_entry& dir);

	void init(const char* _name, int _num);
	void clone(const sector_dir_entry& dir);
};

class sector_dir
{
public:
	sector_dir_entry dirs[16];

public:
	sector_dir();
	sector_dir operator=(const sector_dir& sec_dir);

	bool write_back_to_disk(Buffer& buffer, int sec_num);
	bool read_dir_from_disk(Buffer& buffer, int sec_num);
};

class sector_file
{
public:
	char data[508];
	int next;

public:
	sector_file();
	sector_file operator=(const sector_file& sec_file);

	bool write_back_to_disk(Buffer& buffer, int sec_num);
	bool read_dir_from_disk(Buffer& buffer, int sec_num);
};
