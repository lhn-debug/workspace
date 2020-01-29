#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstring>

using namespace std;

int main()
{
	static int count = 70;
	srand((unsigned int)time(NULL));
	while(count--)
	{
		int num1 = 100 + rand() % 900;
		int num2 = 10 + rand() % 90;
		if(count % 2 == 0)
		{
			int res = 0;
			int ans = num1 * num2;
			cout<<"[ "<<140 - count<<" ] "<<num1<<" * "<<num2<<" = "<<endl;
			cout<<"Please Input Your Answer: ";
			while(1)
			{
				cin>>res;
				if(res == -1)
				{
					break;
				}
				if(res == ans)
				{
					cout<<"OK!"<<endl;
					break;
				}
				else
				{
					cout<<"Try Again: ";
				}
			}
			/*
			char * ch = (char *)malloc(sizeof(char) * 20);
			ch[19] = '\n';
			sprintf(ch, "[%d]%d*%d=\n", 140-count, num1, num2);
			FILE *fp = fopen("ans.txt", "a");
			fwrite(ch, strlen(ch), 1, fp);
			fclose(fp);
			
			char * ch2 = (char *)malloc(sizeof(char) * 20);
			ch2[19] = '\n';
			sprintf(ch2, "[%d]%d*%d=%d\n", 140-count, num1, num2, ans);
			FILE *fp2 = fopen("ans2.txt", "a");
			fwrite(ch2, strlen(ch2), 1, fp2);
			fclose(fp2);*/
		}
		else
		{
			int res1 = 0, res2 = 0;
			int ans = num1 / num2;
			int yu = num1 - ans * num2;
			cout<<"[ "<<140 - count<<" ] "<<num1<<" / "<<num2<<" = "<<endl;
			cout<<"Please Input Your Answer: ";
			while(1)
			{
				cin>>res1;
				cin>>res2;
				if(res1 == -1 && res2 == -1)
				{
					break;
				}
				if(res1 == ans && res2 == yu)
				{
					cout<<"OK!"<<endl;
					break;
				}
				else
				{
					cout<<"Try Again: ";
				}
			}
			/*char * ch = (char *)malloc(sizeof(char) * 20);
			ch[19] = '\n';
			sprintf(ch, "[%d]%d/%d=\n", 140-count, num1, num2);
			FILE *fp = fopen("ans.txt", "a");
			fwrite(ch, strlen(ch), 1, fp);
			fclose(fp);
			
			char * ch2 = (char *)malloc(sizeof(char) * 20);
			ch2[19] = '\n';
			sprintf(ch2, "[%d]%d/%d=%d...%d\n", 140-count, num1, num2, ans, yu);
			FILE *fp2 = fopen("ans.txt", "a");
			fwrite(ch2, strlen(ch2), 1, fp2);
			fclose(fp2);*/
		}
	}
	return 0;
}
