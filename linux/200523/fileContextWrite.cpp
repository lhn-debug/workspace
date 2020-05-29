#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main()
{
	//system("touch file2");
	std::ofstream ofs("file");
	for(int i = 0; i < 100; i++)
	{
		ofs<<"***This is number "<<i<<" lines in this file***"<<std::endl;
	}
	ofs.close();

	string str, line;
	std::ifstream ifs("file");
	while(getline(ifs, line)){
		str += (line + "\n");
	}
	ifs.close();
	cout<<str<<endl;
	return 0;
}
