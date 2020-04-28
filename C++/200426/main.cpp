#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct node{   // 节点类型
    struct node *next;
    unsigned int level;  // 层数
    char *name;    // 文件名
    char fullname[256];   // 绝对路径/相对路径
}filenode;

typedef struct head{   //所要模拟的队列头节点类型
    struct node* head;   //head
    struct node* rear;   //last
}headnode;


void Print(filenode * cur)  //输出每个文件
{
    int i;
    printf("|");
    for(i=0; i<cur->level; i++){
        printf("    ");
    }
    if( i == 0)
        printf("--- ");
    else
        printf("|-- ");
    printf("%-4s\n",cur->name);
}

void Free(filenode * cur)   //释放
{
    free(cur->name);
    free(cur);
}
void Print_dir(headnode * link_stack)  // 输出
{
    filenode * cur = link_stack->head;
    filenode * next = cur->next;
    while(next != NULL){
        Print(cur);
        Free(cur);
        cur = next;
        next = next->next;
    }
}

void read_dir_link(char* dirname, headnode *link_stack ,int level)   //对目录文件进行读取
{
    if(dirname == NULL)
        return;

    struct stat stat_dst;
    if(lstat(dirname, &stat_dst) == -1)   // 读取文件属性
        perror("lstat"),exit(1);
    if(!S_ISDIR(stat_dst.st_mode)){   // 如果文件不是目录文件则直接添加到队列末尾
            filenode* link = NULL;
            link = (filenode*)malloc(sizeof(filenode));
            // 节点初始化
            link->next = NULL;
            link->level = level;
            link->name = (char*)malloc(strlen(link_stack->rear->name) + 1);
            memset(link->name, 0x00, strlen(link_stack->rear->name));
            memcpy(link->name, link_stack->rear->name, strlen(link_stack->rear->name));
            sprintf(link->fullname, "%s/%s\0", dirname,link->name); // 保存绝对路径/相对路径
            // 插入队列中
            if(link_stack->head == NULL){ 
                link_stack->head = link;
                link_stack->rear = link;
            }else{
                link_stack->rear->next = link;
                link_stack->rear = link;
            }
            return;
    }
    // 是目录文件
    DIR *dirp = opendir(dirname);  // 打开目录流
    if(dirp == NULL)
        perror("opendir"),exit(1);
    struct dirent *dp;
    while((dp = readdir(dirp)) != NULL)  // 读取目录文件信息
    {
        if( *(dp->d_name) == '.')
            continue;
            filenode* link = NULL;
            // 节点初始化
            link = (filenode*)malloc(sizeof(filenode));
            link->next = NULL;
            link->level = level;
            link->name = (char*)malloc(strlen(dp->d_name) + 1);
            memset(link->name, 0x00, strlen(dp->d_name) + 1);
            memcpy(link->name, dp->d_name, strlen(dp->d_name));
            sprintf(link->fullname, "%s/%s\0", dirname,link->name);
            // 插入队列
            if(link_stack->head == NULL){
                link_stack->head = link;
                link_stack->rear = link;
            }else{
                link_stack->rear->next = link;
                link_stack->rear = link;
            }
            struct stat stat_src;
            lstat(link->fullname, &stat_src);
            if(S_ISDIR(stat_src.st_mode)){  // 如果是目录文件，则进行递归遍历，并且层数 + 1
                read_dir_link(link->fullname, link_stack, level + 1);
            }
        }
    closedir(dirp); // 关闭目录流
}

void read_dir(char *dirname, headnode* link_stack, int level)
{
    if(dirname == NULL)
        return;
    headnode * ret = NULL;
    read_dir_link(dirname, link_stack, level);
}

void Str(char *dirname, int len)  // 对第一个输入文件的进行格式输出
{
    char* dst = (char*)malloc(len + 2);
    memset(dst, 0x00, len + 2);
    memcpy(dst, dirname, len);
    char *cur = dst;
    char *next = dst;
    while( *next != '\0'){
        if( (*next) == '/' ){
            cur = ++next;
        }
        next++;
    }
    printf("%s\n", cur);
    free(dst);
}
int main(int argc, char*argv[] ){
    if(argc != 2)  // 参数判断
        perror("argc != 2"),exit(1);

    struct stat stat_src;
    if( lstat(argv[1], &stat_src) == -1 )
        perror("lstat"),exit(1);
    // 读取文件信息
    if( S_ISREG(stat_src.st_mode) )  // 如果是普通文件则可以直接输出
        printf("%s\n", argv[1]),exit(1);
    else if( S_ISDIR(stat_src.st_mode) ){  // 目录文件
        headnode * link_stack = (headnode *)malloc(sizeof(headnode));

        if(link_stack == NULL)
            perror("malloc"),exit(1);
        // 头节点初始化
        link_stack->head = NULL;
        link_stack->rear = NULL;
        int len = strlen(argv[1]);
        Str(argv[1], len);
        // 进行遍历
        read_dir(argv[1], link_stack, 0);
        Print_dir(link_stack); // 输出
        free(link_stack); // 释放
        }
}

