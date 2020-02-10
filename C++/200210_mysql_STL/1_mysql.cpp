#include<my_global.h>
#include<mysql.h>
#include<stdio.h>
#include<iostream>

using namespace std;

static const char * host = "localhost";
static const char * user = "root";
static const char * password = "123456";
static const char * database = "connection_test";

static void finish_with_error(MYSQL * con)
{
	fprintf(stderr, "MYSQL Running Error: %s\n", mysql_error(con));
	if(con)
	{
		mysql_close(con);
	}
	exit(EXIT_FAILURE);
}

int main()
{
	MYSQL * con = mysql_init(nullptr);
	if(con == nullptr)
	{
		finish_with_error(con);
	}

	if(mysql_real_connect(con, host, user, password, database, 0, nullptr, 0) == nullptr)
	{
		finish_with_error(con);
	}

	if(mysql_set_character_set(con, "utf8") != 0)
	{
		finish_with_error(con);
	}

	char id[10], val_1[20], val_2[20];
	cout<<"Input Id:";
	cin>>id;
	cout<<"Input Val_1:";
	cin>>val_1;
	cout<<"Input Val_2:";
	cin>>val_2;
	char insert[1000];
	sprintf(insert, "insert into table_test values('%s', '%s', '%s')", id, val_1, val_2);
	cout<<insert<<endl;

	if(mysql_query(con, insert))
	{
		finish_with_error(con);
	}

	char query[1000];
	sprintf(query, "select * from table_test");
	cout<<query<<endl;
	
	if(mysql_query(con, query))
	{
		finish_with_error(con);
	}

	MYSQL_RES * res = mysql_store_result(con);
	if(res == nullptr)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(res);
	cout<<"rows count:"<<num_fields<<endl;

	MYSQL_ROW row;
	while(row = mysql_fetch_row(res))
	{
		unsigned long * lengths;
		lengths = mysql_fetch_lengths(res);
		for(int i = 0; i < num_fields; ++i)
		{
			cout<<"["<<(int)lengths[i]<<"]"<<(row[i]?row[i]:nullptr)<<"  ";
		}
		cout<<endl;
	}

	mysql_free_result(res);
	mysql_close(con);
	return 0;
}
