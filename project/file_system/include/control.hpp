/*
 * control.hpp
 */

#pragma once

#include<unistd.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>
#include<unordered_map>
#include"myinclude.hpp"

static string PATH = "";
static unordered_multimap<string, string> FILE_BUCKET;
static unordered_multimap<string, string> DIR_BUCKET;

using namespace std;

class file_system
{
private:
	superblock sp;
	Inode cur_dir_node;
	sector_dir cur_dir;
	Buffer my_cache;
public:
	void myshell();
	void run();
	file_system();
private:
	void help(string command, string args = "");
	void show_manu();
	bool new_line(string& command);
	bool deal_input(const vector<string>& command);
	void deal_help(string args = "");
	bool format_file_system();
	bool list_dir();
	bool change_dir(const char* name);
	bool find_dir(const char* name);
	bool vi_file(const char* name);
	bool make_dir(const char* name);
	bool touch(const char* name);
	bool remove_dir(const char* name);
	bool del_inode(Inode& node, sector_dir& del_dir);
	bool init_file_system();
};
