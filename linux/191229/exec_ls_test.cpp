#include<unistd.h>

int main()
{
	char *const argv[] = {"ls","-l",NULL};
	char *const envp[] = {"PATH=/bin:/usr/bin","TERM=console",NULL};
	execve("/bin/ls",argv,envp);
	return 0;
}
