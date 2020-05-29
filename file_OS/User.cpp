#include "./include/User.h"
#include "./include/Utility.h"
#include <iostream>
#include <fstream>
using namespace std;

extern FileManager g_FileManager;

void User::deal(const string& str, const bool is_file)
{
	string name, path;
	size_t pos = str.rfind('/');
	name = str.substr(pos + 1, str.size());
	path = str.substr(0, pos + 1);
	if(pos == 0)
	{
		path = "/";
	}
	fs_hash_map.insert(make_pair(path, name));
	if(is_file)
	{
		file_hash_map.insert(make_pair(name, path));
	}
	else
	{
		dir_hash_map.insert(make_pair(name, path));
	}
}

User::User() {
    u_error = U_NOERROR;
    fileManager = &g_FileManager;
	dirp = "/";
    curDirPath = "/";
    //fileManager->Open();
	cdir = fileManager->rootDirINode;
    pdir = NULL;
    Utility::memset(arg, 0, sizeof(arg));

	string tmp;

	ifstream fifs("file_bak");
	while(fifs>>tmp)
	{
		deal(tmp, true);
	}

	ifstream difs("dir_bak");
	while(difs>>tmp)
	{
		deal(tmp, false);
	}

	fifs.close();
	difs.close();

	printf("User finished!\n");
}

User::~User() {
}

void User::Exit(){
	ofstream fofs("file_bak");
	ofstream dofs("dir_bak");
	
	for(auto it = file_hash_map.begin(); it != file_hash_map.end(); ++it)
	{
		string tmp = it->second + it->first;
		fofs<<tmp<<endl;
	}

	for(auto it = dir_hash_map.begin(); it != dir_hash_map.end(); ++it)
	{
		string tmp = it->second + it->first;
		dofs<<tmp<<endl;
	}

	fofs.close();
	dofs.close();

	exit(0);
}

void User::Mkdir(string dirName) {
    if (!checkPathName(dirName)) {
        return;
    }
    arg[1] = INode::IFDIR;
    fileManager->Creat();
    if(!IsError())
	{
		dir_hash_map.insert(make_pair(dirName, curDirPath));
		fs_hash_map.insert(make_pair(curDirPath, dirName));
	}
}

void User::Ls() {
    ls.clear();
    fileManager->Ls();
    if (IsError()) {
        return;
    }
    cout << ls << endl;

	auto it = fs_hash_map.find(curDirPath);
	for(int k = 0; k != fs_hash_map.count(curDirPath); k++, it++)
	{
		cout<<"[curDirPath]"<<it->first<<" => "<<it->second<<endl;
	}

	cout<<endl;

	for(auto it = fs_hash_map.begin(); it != fs_hash_map.end(); it++)
	{		
		cout<<"[allDirPath]"<<it->first<<" => "<<it->second<<endl;
	}
}

void User::Cd(string dirName) {
    if (!checkPathName(dirName)) {
        return;
    }
    fileManager->ChDir();
    IsError();
}

void User::Create(string fileName, string mode) {
    if (!checkPathName(fileName)) {
        return;
    }
    int md = INodeMode(mode);
    if (md == 0) {
        cout << "this mode is undefined !  \n";
        return;
    }

    arg[1] = md;
    fileManager->Creat();
    if(!IsError())
	{
		file_hash_map.insert(make_pair(fileName, curDirPath));
		fs_hash_map.insert(make_pair(curDirPath, fileName));
	}
}

void User::Delete(string fileName) {
    if (!checkPathName(fileName)) {
        return;
    }
    fileManager->UnLink();
    if(!IsError())
	{
		/*删除文件哈希容器中当前目录下的文件*/
		auto fit = file_hash_map.find(fileName);
		for(int k = 0; k != file_hash_map.count(fileName); k++, fit++)
		{
			if(curDirPath == fit->second)
			{
				file_hash_map.erase(fit);
				break;
			}
		}

		/*删除系统容器中要删除的直接目录*/
		auto fs_it = fs_hash_map.find(curDirPath);
		for(int k = 0; k != fs_hash_map.count(curDirPath); k++, fs_it++)
		{
			if(fileName == fs_it->second)
			{
				fs_hash_map.erase(fs_it);
				break;
			}
		}
		
		/*删除系统容器中要删除的间接目录下的目录*/
		for(auto it = fs_hash_map.begin(); it != fs_hash_map.end(); )
		{
			if((it->first).substr(0, strlen((curDirPath + fileName + "/").c_str())) == (curDirPath + fileName + "/"))
			{
				it = fs_hash_map.erase(it);
			}
			else
			{
				it++;
			}
		}
		
		/*删除目录哈希容器中当前目录下的目录*/
		for(auto dir_it = dir_hash_map.begin(); dir_it != dir_hash_map.end(); )
		{
			if((curDirPath == dir_it->second && fileName == dir_it->first)
						|| ((dir_it->second).substr(0, strlen((curDirPath + fileName + "/").c_str())) == (curDirPath + fileName + "/")))
			{
				dir_it = dir_hash_map.erase(dir_it);
			}
			else
			{
				dir_it++;
			}
		}
		
		/*删除文件哈希容器中当前目录下的文件*/
		for(auto dir_it = file_hash_map.begin(); dir_it != file_hash_map.end(); )
		{
			if((curDirPath == dir_it->second && fileName == dir_it->first)
						|| ((dir_it->second).substr(0, strlen((curDirPath + fileName + "/").c_str())) == (curDirPath + fileName + "/")))
			{
				dir_it = file_hash_map.erase(dir_it);
			}
			else
			{
				dir_it++;
			}
		}
/*
		for(auto it = tmp.begin(); it != tmp.end(); it++)
		{
			cout<<*it<<endl;
		}
*/
/*
		auto dit = dir_hash_map.find(fileName);
		for(int k = 0; k != dir_hash_map.count(fileName); k++)
		{
			if((dit->second).substr(0, strlen((curDirPath + fileName + "/").c_str())) == (curDirPath + fileName + "/") || (fileName == dit->second))
			{
				dit = dir_hash_map.erase(dit);
			}
			else
			{
				dit++;
			}
		}
*/
	}
}

void User::Open(string fileName, string mode) {
    if (!checkPathName(fileName)) {
        return;
    }
    int md = FileMode(mode);
    if (md == 0) {
        cout << "this mode is undefined ! \n";
        return;
    }

    arg[1] = md;
    fileManager->Open();
    if (IsError())
        return;
    cout << "open success, return fd=" << ar0[EAX] << endl;
}

void User::Close(string sfd) {
    if (sfd.empty() || !isdigit(sfd.front())) {
        cout << "parameter fd can't be empty or be nonnumeric ! \n";
        return;
    }
    arg[0] = stoi(sfd);;
    fileManager->Close();
    IsError();
}

void User::Seek(string sfd, string offset, string origin) {
    if (sfd.empty() || !isdigit(sfd.front())) {
        cout << "parameter fd can't be empty or be nonnumeric ! \n";
        return;
    }
    if (offset.empty()) {
        cout << "parameter offset can't be empty ! \n";
        return;
    }
    if (origin.empty() || !isdigit(origin.front())) {
        cout << "parameter origin can't be empty or be nonnumeric ! \n";
        return;
    }
    arg[0] = stoi(sfd);
    arg[1] = stoi(offset);
    arg[2] = stoi(origin);
    fileManager->Seek();
    IsError();
}

void User::Write(string sfd, string inFile, string size) {
    if (sfd.empty() || !isdigit(sfd.front())) {
        cout << "parameter fd can't be empty or be nonnumeric ! \n";
        return;
    }
    int fd = stoi(sfd);

    int usize;
    if (size.empty() || (usize = stoi(size)) < 0) {
        cout << "parameter size must be greater or equal than 0 ! \n";
        return;
    }

    char *buffer = new char[usize];
    fstream fin(inFile, ios::in | ios::binary);
    if (!fin) {
        cout << "file " << inFile << " open failed ! \n";
        return;
    }
    fin.read(buffer, usize);
    fin.close();
    //cout << "fd = " << fd << " inFile = " << inFile << " size = " << usize << "\n";
    arg[0] = fd;
    arg[1] = (long)buffer;
    arg[2] = usize;
    fileManager->Write();

    if (IsError())
        return;
    cout << "write " << ar0[User::EAX] << "bytes success !" << endl;
    delete[]buffer;
}

void User::Read(string sfd, string outFile, string size) {
    if (sfd.empty() || !isdigit(sfd.front())) {
        cout << "parameter fd can't be empty or be nonnumeric ! \n";
        return;
    }
    int fd = stoi(sfd);

    int usize;
    if (size.empty() || !isdigit(size.front()) || (usize = stoi(size)) < 0) {
        cout << "parameter size is not right \n";
        return;
    }
    char *buffer = new char[usize];
    //cout << "fd = " << fd << " outFile = " << outFile << " size = " << size << "\n";
    arg[0] = fd;
    arg[1] = (long)buffer;
    arg[2] = usize;
    fileManager->Read();
    if (IsError())
        return;

    cout << "read " << ar0[User::EAX] << " bytes success : \n" ;
    if (outFile.empty()) {
        for (unsigned int i = 0; i < ar0[User::EAX]; ++i) {
            cout << (char)buffer[i];
        }
        cout << " \n";
        return;
    }
    fstream fout(outFile, ios::out | ios::binary);
    if (!fout) {
        cout << "file " << outFile << " open failed ! \n";
        return;
    }
    fout.write(buffer, ar0[User::EAX]);
    fout.close();
    cout << "read to " << outFile << " done ! \n";
    delete[]buffer;
}

void User::DFind(string dirName)
{
	auto it = dir_hash_map.find(dirName);
	for(int k = 0; k != dir_hash_map.count(dirName); k++, it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

void User::FFind(string fileName)
{
	auto it = file_hash_map.find(fileName);
	for(int k = 0; k != file_hash_map.count(fileName); k++, it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

int User::INodeMode(string mode) {
    int md = 0;
    if (mode.find("-r") != string::npos) {
        md |= INode::IREAD;
    }
    if (mode.find("-w") != string::npos) {
        md |= INode::IWRITE;
    }
    if (mode.find("-rw") != string::npos) {
        md |= (INode::IREAD | INode::IWRITE);
    }
    return md;
}

int User::FileMode(string mode) {
    int md = 0;
    if (mode.find("-r") != string::npos) {
        md |= File::FREAD;
    }
    if (mode.find("-w") != string::npos) {
        md |= File::FWRITE;
    }
    if (mode.find("-rw") != string::npos) {
        md |= (File::FREAD | File::FWRITE);
    }
    return md;
}

bool User::checkPathName(string path) {
    // FileManager 中函数不判断参数的合法性，最好在User中过滤，
    // 暂不考虑过多的参数不合法情况
    if (path.empty()) {
        cout << "parameter path can't be empty ! \n";
        return false;
    }

    if (path.substr(0, 2) != "..") {
        dirp = path;
    }
    else {
        string pre = curDirPath;
        unsigned int p = 0;
        //可以多重相对路径 .. ../ ../.. ../../
        for (; pre.length() > 3 && p < path.length() && path.substr(p, 2) == ".."; ) {
            pre.pop_back();
            pre.erase(pre.find_last_of('/') + 1);
            p += 2;
            p += p < path.length() && path[p] == '/';
        }
        dirp = pre + path.substr(p);
    }

    if (dirp.length() > 1 && dirp.back() == '/') {
        dirp.pop_back();
    }

    for (unsigned int p = 0, q = 0; p < dirp.length(); p = q + 1) {
        q = dirp.find('/', p);
        q = min(q, (unsigned int)dirp.length());
        if (q - p > DirectoryEntry::DIRSIZ) {
            cout << "the fileName or dirPath can't be greater than 28 size ! \n";
            return false;
        }
    }
    return true;
}

bool User::IsError() {
    if (u_error != U_NOERROR) {
        cout << "errno = " << u_error;
        EchoError(u_error);
        u_error = U_NOERROR;
        return true;
    }
    return false;
}

void User::EchoError(enum ErrorCode err) {
    string estr;
    switch (err) {
    case User::U_NOERROR:
        estr = " No u_error ";
        break;
    case User::U_ENOENT:
        estr = " No such file or directory ";
        break;
    case User::U_EBADF:
        estr = " Bad file number ";
        break;
    case User::U_EACCES:
        estr = " Permission denied ";
        break;
    case User::U_ENOTDIR:
        estr = " Not a directory ";
        break;
    case User::U_ENFILE:
        estr = " File table overflow ";
        break;
    case User::U_EMFILE:
        estr = " Too many open files ";
        break;
    case User::U_EFBIG:
        estr = " File too large ";
        break;
    case User::U_ENOSPC:
        estr = " No space left on device ";
        break;
    default:
        break;
    }
    cout << estr << endl;
}
