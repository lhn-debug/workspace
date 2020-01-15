#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	string str;
	str.append("Hello");
	str.push_back(' ');
	str += "Linux";
	cout<<str<<endl;
	cout<<str.c_str()<<endl;

	//获取文件后缀
	string file("file.cpp");
	cout<<file<<endl;
	size_t pos = file.find('.');
	string suffix(file.substr(pos, file.size()-pos));
	cout<<suffix<<endl;

	//截取url中的域名
	string url("http://github.com/lhn-debug/workspace.git");
	cout<<url<<endl;
	size_t start = url.find("://");
	//static const size_t npos = -1
	//npos是string中的一个静态成员变量
	if(start == string::npos)
	{
		cout<<"invalid url"<<endl;
		return 0;
	}
	start += 3;
	size_t end = url.find('/', start);
	string address = url.substr(start, end - start);
	cout<<address<<endl;

	//删除url的协议前缀
	size_t del = url.find("://");
	url.erase(0, pos + 3);
	cout<<url<<endl;
	return 0;
}
