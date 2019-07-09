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
#include<sys/select.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<pwd.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<errno.h>


int main(int argc,char** argv)
{
    if(argc!=2){
        printf("./test port");
        exit(1);
    }
    int lfd,maxfd,opt,ret,len,cfd;
    struct sockaddr_in serv_addr,clnt_addr;
    fd_set reads,temp;
    char buf[256];

    lfd=socket(AF_INET,SOCK_STREAM,0);
    if(lfd==-1){
        perror("socket err");
        exit(1);
    }
    
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    opt=1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt));
    if(bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1){
        perror("bind err");
        exit(1);
    }
    if(listen(lfd,128)==-1){
        perror("listen err");
        exit(1);
    }

    FD_ZERO(&reads);
    FD_SET(lfd,&reads);
    maxfd=lfd;
    printf("wait for connect...\n");
    while(1){
        temp=reads;
        ret=select(maxfd+1,&temp,NULL,NULL,NULL);
        
        if(FD_ISSET(lfd,&temp)){
            len=sizeof(clnt_addr);
            cfd=accept(lfd,(struct sockaddr*)&clnt_addr,&len);
            printf("client connect\n");
            FD_SET(cfd,&reads);
            maxfd=maxfd<cfd? cfd:maxfd;
        }
        for(int i=lfd+1;i<=maxfd;++i){
            if(FD_ISSET(i,&temp)){
                len=read(i,buf,sizeof(buf));
                if(len==0){
                    FD_CLR(i,&reads);
                }
                if(len==-1){
                    perror("read err");
                    exit(1);
                }
                for(int j=0;j<len;j++){
                    buf[j]=toupper(buf[j]);
                }
                write(i,buf,strlen(buf));
            }
        }
    }
    
    return 0;
}
