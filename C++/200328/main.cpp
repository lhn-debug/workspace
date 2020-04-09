#include<iostream>
#include<string>
#include<vector>
#include<unistd.h>
#include<unordered_set>
#include<unordered_map>
#include<map>

using namespace std;

void view_dynamic(const string& find_str, unordered_multiset<string> ums)
{
	for(auto e : ums)
	{
		sleep(1);
		if(find_str == e)
		{
			cout<<"=>"<<e<<endl;
		}
		else
		{
			cout<<"  "<<e<<endl;
		}
	}
}

int main()
{
	unordered_multimap<int, int> dir_node;
	unordered_map<int, string> dir_name;
	dir_node.insert(make_pair(0, 1));
	dir_name.insert(make_pair(1, "/bin"));
	dir_node.insert(make_pair(0, 2));
	dir_name.insert(make_pair(2, "/var"));
	dir_node.insert(make_pair(2, 3));
	dir_name.insert(make_pair(3, "/src"));
	dir_node.insert(make_pair(3, 4));
	dir_name.insert(make_pair(4, "/obj"));
	dir_node.insert(make_pair(3, 5));
	dir_name.insert(make_pair(5, "/bin"));
	dir_node.insert(make_pair(3, 6));
	dir_name.insert(make_pair(6, "/img"));
	dir_node.insert(make_pair(6, 7));
	dir_name.insert(make_pair(7, ""));
	for(auto& e : dir_node)
	{
		cout<<e.first<<" "<<e.second<<" "<<dir_name[e.second]<<endl;
	}
	for(int i = 0; i < dir_node.bucket_count(); i++)
	{
		cout<<dir_node.bucket_size(i)<<endl;
	}
	for(unordered_multimap<int, int>::local_iterator li = dir_node.begin(0);
		li != dir_node.end(0); li++)
	{
		cout<<(*li).first<<" "<<(*li).second<<" "<<dir_name[(*li).second]<<endl;
	}
	vector<int> visit_line = {2, 3, 6};
	string visit_name = "";
	for(int i = 0; i < visit_line.size(); i++)
	{
		visit_name.append(dir_name[visit_line[i]]);
	}
	cout<<visit_name<<endl;
	return 0;
}
