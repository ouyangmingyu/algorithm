/*************************************************************************
> File Name: touch.c
> Author: 
> Mail: 
> Created Time: 2018年12月19日 星期三 15时59分05秒
************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<pwd.h>
#include<signal.h>
#include<arpa/inet.h>
#include<ctype.h>



int main(int argc,char** argv)
{

    if(argc!=3){
        printf("test ip port \n");
        return -1;
    }
    char buf[4096];
    int sfd,len;
    struct sockaddr_in serv_addr;
    sfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(atoi(argv[2]));
    inet_pton(AF_INET,argv[1],&serv_addr.sin_addr.s_addr);

    connect(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    while(1){
        fgets(buf,sizeof(buf),stdin);
        write(sfd,buf,strlen(buf));
        len=read(sfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
    }
    return 0;
}
