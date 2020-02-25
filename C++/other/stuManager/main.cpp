#include<iostream>
#include<vector>
#include<cstring>

#define MAX_SIZE 10

using namespace std;

typedef struct StuInfo
{
	char _sno[MAX_SIZE];
	char _sname[MAX_SIZE];
}StuInfo;

typedef struct StuScore
{
	double _spoint;
	size_t _srank;
}StuScore;

typedef struct Stu
{
	StuInfo _sinfo;
	StuScore _sscore;
}Stu;

template<class T>
class StuData{};

template<>
class StuData<Stu>
{
friend ostream& operator<<(ostream& _cout, const StuData<Stu>& studata);
friend istream& operator>>(istream& _cin, StuData<Stu>& studata);

public:
	StuData()
	{};

	void insertInfo()
	{
		cin>>*this;
	}

	void selectAllInfo()
	{
		cout<<*this;
	}
	
	void findFromSno(const char * sno, vector<Stu>& s)
	{
		for(auto x : _stu)
		{
			if(strcmp(x._sinfo._sno, sno) == 0)
			{
				s.push_back(x);
			}
		}
	}

	void printVector(vector<Stu>& s)
	{
		for(auto x : s)
		{
			cout<<x._sinfo._sno<<endl;
			cout<<x._sinfo._sname<<endl;
			cout<<x._sscore._spoint<<endl;
			cout<<x._sscore._srank<<endl;
		}	
	}
private:
	vector<Stu> _stu;
};

ostream& operator<<(ostream& _cout, const StuData<Stu>& studata)
{
	for(auto x : studata._stu)
	{
		_cout<<x._sinfo._sno<<" "<<x._sinfo._sname<<" "<<x._sscore._spoint<<" "<<x._sscore._srank<<endl;
	}
	return _cout;
}

istream& operator>>(istream& _cin, StuData<Stu>& studata)
{
	Stu s;
	cout<<"SNO>>";
	_cin>>s._sinfo._sno;
	cout<<"SNAME>>";
	_cin>>s._sinfo._sname;
	cout<<"SPOINT>>";
	_cin>>s._sscore._spoint;
	cout<<"SRANK>>";
	_cin>>s._sscore._srank;
	studata._stu.push_back(s);
	return _cin;
}

int main()
{
	StuData<Stu> sd;
	sd.insertInfo();
	sd.selectAllInfo();
	sd.insertInfo();
	sd.selectAllInfo();
	sd.insertInfo();
	sd.selectAllInfo();
	vector<Stu> v;
	sd.findFromSno("2", v);
	sd.printVector(v);
	return 0;
}
