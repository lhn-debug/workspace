/*
 * main.cpp
 */

#include"../include/control.hpp"

int main()
{
	file_system *fs = new file_system;
	fs->run();
	delete fs;
	fs = NULL;
	return 0;
}
