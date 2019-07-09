#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int n =5;
    int i ;
    pid_t pid ;
    for(i = 0; i < 5 ; i ++){
        pid = fork();
        if(pid == 0){
            break;
        }
    }
    if(i == 5){
        //parent 
        printf("I am parent!");
        //如何使用waitpid回收?  -1 代表子进程都死了，都收了
        while(1){
            pid_t wpid = waitpid(-1,NULL,WNOHANG);
            if(wpid == -1){
                break;
            }
            else if(wpid > 0){
                printf("waitpid wpid=%d\n",wpid);
            }
        }
        while(1){
            sleep(1);
        }
    }
    if(i < 5){
//        sleep(i);
        printf("I am child,i =%d,pid=%d\n",i,getpid());
    }
    return 0;
}
