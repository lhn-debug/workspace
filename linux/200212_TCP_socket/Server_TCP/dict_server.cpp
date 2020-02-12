#include"tcp_server.hpp"
#include<unordered_map>

using namespace std;

std::unordered_map<std::string, std::string> g_dict;

void Translate(const std::string& req, std::string *resp)
{
	auto it = g_dict.find(req);
	if(it == g_dict.end())
	{
		*resp = "Not Found...";
		return ;
	}
	*resp = it->second;
	return ;
}

void Dict()
{
	g_dict.insert(std::make_pair("template","模板"));
	g_dict.insert(std::make_pair("iterator","迭代器"));
	g_dict.insert(std::make_pair("unorder","无序"));
	g_dict.insert(std::make_pair("array","数组"));
	g_dict.insert(std::make_pair("database","数据库"));
	g_dict.insert(std::make_pair("insert","插入"));
	g_dict.insert(std::make_pair("delete","删除"));
	g_dict.insert(std::make_pair("update","修改"));
	g_dict.insert(std::make_pair("select","查询"));
	g_dict.insert(std::make_pair("string","字符串"));
}

int main(int argc, char *argv[])
{
	if(argc < 0)
	{
		printf("Use ./dict_server [IP] [PORT]\n");
		return 1;
	}
	Dict();
	tcp_server server(argv[1], atoi(argv[2]));
	server._start(Translate);
	return 0;
}
