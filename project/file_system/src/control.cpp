/*
 * control.cpp
 */

#include"../include/control.hpp"

file_system::file_system()
{
	system("clear");
	cout<<endl<<"********************文件系统启动********************"<<endl;
}

void file_system::myshell()
{
	string input, tem;
	vector<string> commands;

	while(true)
	{
		if(new_line(input))
		{
			stringstream ss(input);
			while(ss >> tem)
			{
				commands.push_back(tem);
			}
			if(!deal_input(commands))
			{
				break;
			}
		}
		commands.clear();
	}

	return ;
}

void file_system::run()
{
	myshell();
	return;
}

void file_system::help(string command, string args)
{

}

void file_system::show_manu()
{
	cout<<"help information"<<endl;
	cout<<"Use: help <command>"<<endl;
	cout<<"Example: 'help' or 'help [command]'"<<endl;
	cout<<"command information"<<endl;
	cout<<"[reformat|ls|cd|mkdir|touch|rm]"<<endl;
}

bool file_system::new_line(string& command)
{
	cout<<"[file_system@localhost]#";
	
	string tem;
	bool flag = false;

	while(getline(cin, tem))
	{
		if(tem.empty())
		{
			break;
		}
		else
		{
			command = tem;
		}
		flag = true;
	}

	return flag;
}

bool file_system::deal_input(const vector<string>& command)
{
	if(command.size() == 0)
	{
		return true;
	}

	string comm = command[0];

	if(comm == "help")
	{
		if(command.size() == 1)
		{
			deal_help();
		}
		else
		{
			deal_help(command[1]);
		}
	}
	else if(comm == "dfind")
	{
		if(command.size() == 1)
		{
			deal_help();
		}
		else
		{
			const char * dir = command[1].c_str();
			find_dir(dir);
		}
	}
	else if(comm == "ls")
	{
		list_dir();
	}
	else if(comm == "pwd")
	{
		cout<<PATH<<endl;
	}
	else if(comm == "exit")
	{
		cout<<"退出系统"<<endl;
		return false;
	}
	else if(comm == "cd")
	{
		const char * dir = command[1].c_str();
		change_dir(dir);
	}
	else if(comm == "reformat")
	{
		format_file_system();
	}
	else if(comm == "mkdir")
	{
		const char * dir = command[1].c_str();
		make_dir(dir);
	}
	else if(comm == "touch")
	{
		const char * file = command[1].c_str();
		touch(file);
	}
	else if(comm == "rm")
	{
		const char * del_name = command[1].c_str();
		remove_dir(del_name);
	}
	else
	{
		cout<<"没有这条命令，请输入help查看相关帮助信息"<<endl;
	}
	return true;
}

void file_system::deal_help(string args)
{
	if(args == "")
	{
		show_manu();
	}
	else
	{
		if(args == "ls")
		{
			cout<<"ls <file or dir name>"<<endl;
		}
		else if(args == "touch")
		{
			cout<<"touch <file name>"<<endl;
		}
		else if(args == "mkdir")
		{
			cout<<"mkdir <dir name>"<<endl;
		}
		else if(args == "cd")
		{
			cout<<"cd <dir name>"<<endl;
		}
		else if(args == "rm")
		{
			cout<<"rm <file or dir name>"<<endl;
		}
		else if(args == "reformat")
		{
			cout<<"reformat <init system>"<<endl;
		}
		else
		{
			cout<<"not found this command"<<endl;
		}
	}
}

bool file_system::format_file_system()
{
	cout<<"Init File System Running......"<<endl;
	sleep(1);
	
	sp.init();

	cout<<"creating I-node......"<<endl;
	sleep(1);

	Inode root_node(sp.get_new_inode(), false, 0, sp.get_new_sec());
	Inode bin_node(sp.get_new_inode(), false, 0, sp.get_new_sec());
	Inode etc_node(sp.get_new_inode(), false, 0, sp.get_new_sec());
	Inode home_node(sp.get_new_inode(), false, 0, sp.get_new_sec());
	Inode dev_node(sp.get_new_inode(), false, 0, sp.get_new_sec());
	Inode host_node(sp.get_new_inode(), false, 0, sp.get_new_sec());
	
	cout<<"writing I-node back to disk......"<<endl;
	sleep(1);
	
	root_node.write_inode_back_to_disk(my_cache);
	bin_node.write_inode_back_to_disk(my_cache);
	etc_node.write_inode_back_to_disk(my_cache);
	home_node.write_inode_back_to_disk(my_cache);
	dev_node.write_inode_back_to_disk(my_cache);
	host_node.write_inode_back_to_disk(my_cache);

	cout<<"creating dir......"<<endl;
	sleep(1);

	sector_dir root_sec_dir;
	sector_dir bin_sec_dir;
	sector_dir etc_sec_dir;
	sector_dir home_sec_dir;
	sector_dir dev_sec_dir;
	sector_dir host_sec_dir;

	root_sec_dir.dirs[0].init(".", 1);
	root_sec_dir.dirs[1].init("..", 1);
	root_sec_dir.dirs[2].init("bin", bin_node.get_inode_num());
	root_sec_dir.dirs[3].init("etc", etc_node.get_inode_num());
	root_sec_dir.dirs[4].init("home", home_node.get_inode_num());
	root_sec_dir.dirs[5].init("dev", dev_node.get_inode_num());

	bin_sec_dir.dirs[0].init(".", bin_node.get_inode_num());
	bin_sec_dir.dirs[1].init("..", root_node.get_inode_num());

	etc_sec_dir.dirs[0].init(".", etc_node.get_inode_num());
	etc_sec_dir.dirs[1].init("..", root_node.get_inode_num());

	home_sec_dir.dirs[0].init(".", home_node.get_inode_num());
	home_sec_dir.dirs[1].init("..", root_node.get_inode_num());
	home_sec_dir.dirs[2].init("host", host_node.get_inode_num());

	dev_sec_dir.dirs[0].init(".", dev_node.get_inode_num());
	dev_sec_dir.dirs[1].init("..", root_node.get_inode_num());
	
	host_sec_dir.dirs[0].init(".", host_node.get_inode_num());
	host_sec_dir.dirs[1].init("..", home_node.get_inode_num());

	cout<<"writing dir sector back to disk......"<<endl;
	sleep(1);

	root_sec_dir.write_back_to_disk(my_cache, root_node.get_sec_beg());
	bin_sec_dir.write_back_to_disk(my_cache, bin_node.get_sec_beg());
	etc_sec_dir.write_back_to_disk(my_cache, etc_node.get_sec_beg());
	home_sec_dir.write_back_to_disk(my_cache, home_node.get_sec_beg());
	dev_sec_dir.write_back_to_disk(my_cache, dev_node.get_sec_beg());
	host_sec_dir.write_back_to_disk(my_cache, host_node.get_sec_beg());

	cur_dir = root_sec_dir;
	cur_dir_node = root_node;

	DIR_BUCKET.insert(make_pair("/", "/"));
	DIR_BUCKET.insert(make_pair("bin", "/bin"));
	DIR_BUCKET.insert(make_pair("etc", "/etc"));
	DIR_BUCKET.insert(make_pair("home", "/home"));
	DIR_BUCKET.insert(make_pair("dev", "/dev"));
	DIR_BUCKET.insert(make_pair("host", "/home/host"));
	
	cout<<"Init File System end......"<<endl;

	return true;
}

bool file_system::list_dir()
{
	cout<<PATH<<endl;
	for(int i = 2; i < 15; i++)
	{
		cout<<cur_dir.dirs[i].name<<" ";
	}
	cout<<endl;
	return true;
}

bool file_system::change_dir(const char* name)
{
	int dir_inode_num = -1;

	for(int i = 0; i < 15; i++)
	{
		if(strncmp(name, cur_dir.dirs[i].name, strlen(name)) == 0)
		{
			dir_inode_num = cur_dir.dirs[i].inode_num;
			cout<<"dir I-node number: "<<dir_inode_num<<endl;
			if(strcmp(name, "..") == 0)
			{
				size_t pos = PATH.rfind('/');
				PATH.erase(pos, PATH.size());
			}
			else
			{
				PATH += "/";
				PATH += name;
			}
			break;
		}
	}

	if(dir_inode_num == -1)
	{
		cout<<"not found dir......"<<endl;
		return false;
	}

	cur_dir_node.read_inode_from_disk(dir_inode_num, my_cache);
	cur_dir.read_dir_from_disk(my_cache, cur_dir_node.get_sec_beg());

	return true;
}

bool file_system::find_dir(const char* name)
{
	unordered_multimap<string, string>::iterator it = DIR_BUCKET.find(name);

	for(int k = 0; k != DIR_BUCKET.count(name); k++, it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}

	return true;
}

/*
bool file_system::vi_file(const char* name)
{
	int file_inode_num = -1;

	for(int i = 0; i < 15; i++)
	{
		if((strncmp(name, cur_dir.dirs[i].name, strlen(name)) == 0))
		{
			file_inode_num = cur_dir.dirs[i].inode_num;
			cout<<"file I-node number: "<<file_inode_num<<endl;
			break;
		}
	}

	if(dir_inode_num == -1)
	{
		cout<<"not found dir......"<<endl;
		return false;
	}
	
}
*/

bool file_system::make_dir(const char* name)
{
	cout<<"creating new dir......"<<endl;
	
	Inode new_dir_inode(sp.get_new_inode(), false, 0, sp.get_new_sec());

	new_dir_inode.write_inode_back_to_disk(my_cache);

	sector_dir new_sec_dir;
	new_sec_dir.dirs[0].init(".", new_dir_inode.get_inode_num());
	new_sec_dir.dirs[1].init("..", cur_dir_node.get_inode_num());

	new_sec_dir.write_back_to_disk(my_cache, new_dir_inode.get_sec_beg());

	int flag = false;
	for(int i = 2; i < 15; i++)
	{
		if(cur_dir.dirs[i].inode_num == 0)
		{
			cur_dir.dirs[i].init(name, new_dir_inode.get_inode_num());
			flag = true;
			break;
		}
	}

	if(flag)
	{
		cur_dir.write_back_to_disk(my_cache, cur_dir_node.get_sec_beg());
		DIR_BUCKET.insert(make_pair(name, PATH + "/" + name));
	}

	cout<<"new dir created......"<<endl;

	return flag;
}

bool file_system::touch(const char* name)
{
	cout<<"creating new file"<<endl;
	
	Inode new_file_inode(sp.get_new_inode(), true, 1, sp.get_new_sec());

	new_file_inode.write_inode_back_to_disk(my_cache);

	sector_file new_sec_file;
	new_sec_file.write_back_to_disk(my_cache, new_file_inode.get_sec_beg());
	
	int flag = false;
	for(int i = 2; i < 15; i++)
	{
		if(cur_dir.dirs[i].inode_num == 0)
		{
			cur_dir.dirs[i].init(name, new_file_inode.get_inode_num());
			flag = true;
			break;
		}
	}

	if(flag)
	{
		cur_dir.write_back_to_disk(my_cache, new_file_inode.get_sec_beg());
	}

	cout<<"new file created......"<<endl;

	return flag;
}

bool file_system::remove_dir(const char* name)
{
	int del_inode_num = -1;
	for(int i = 0; i < 15; i++)
	{
		if(strncmp(name, cur_dir.dirs[i].name, strlen(name)) == 0)
		{
			del_inode_num = cur_dir.dirs[i].inode_num;
			cout<<"file/dir I-node number is "<<del_inode_num<<endl;
			break;
		}
	}

	if(del_inode_num == -1)
	{
		cout<<"not fount this file/dir"<<endl;
		return false;
	}

	Inode del_node;
	del_node.read_inode_from_disk(del_inode_num, my_cache);
/*	
	if(del_node.get_type())
	{
		
	}
	else
	{
		unordered_multimap<string, string>::iterator it = DIR_BUCKET.find(name);

		for(int k = 0; k != DIR_BUCKET.count(name); k++, it++)
		{
			if(it->second == (PATH + "/" + name))
			{
				it = DIR_BUCKET.erase(it);
			}
		}
	}
*/
	del_inode(del_node, cur_dir);

	return true;
}

bool file_system::del_inode(Inode& node, sector_dir& del_dir)
{
	cout<<"delete I-node number is "<<node.get_inode_num()<<endl;

	if(node.get_type())
	{
		for(int i = 2; i < 15; i++)
		{
			if(del_dir.dirs[i].inode_num == node.get_inode_num())
			{
				cout<<"delete I-node,delete sector text"<<endl;
				memset(&del_dir.dirs[i], 0, sizeof(sector_dir_entry));
				del_dir.write_back_to_disk(my_cache, node.get_sec_beg());
				break;
			}
		}

		sp.recv_sec(node.get_sec_beg() - BLOCK_BEGIN / 512);
		sp.recv_inode(node.get_inode_num());
	}
	else
	{
		for(int i = 0; i < 15; i++)
		{
			if(node.get_inode_num() == del_dir.dirs[i].inode_num)
			{
				cout<<"delete I-node,delete sector text"<<endl;
				memset(&del_dir.dirs[i], 0, sizeof(sector_dir_entry));
				del_dir.write_back_to_disk(my_cache, node.get_sec_beg());
				break;
			}
		}
		
		sp.recv_sec(node.get_sec_beg() - BLOCK_BEGIN / 512);
		sp.recv_inode(node.get_inode_num());

		Inode new_node;
		new_node = node;
		sector_dir new_dir;
		new_dir = del_dir;

		new_dir.read_dir_from_disk(my_cache, new_node.get_sec_beg());

		for(int i = 2; i < 15; i++)
		{
			if(new_dir.dirs[i].inode_num != 0)
			{
				new_node.read_inode_from_disk(new_dir.dirs[i].inode_num, my_cache);
				del_inode(new_node, new_dir);
			}
		}
	}
}

bool file_system::init_file_system()
{

}
