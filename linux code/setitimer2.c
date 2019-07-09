#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
//typedef void (*sighandler_t)(int);
//
//       sighandler_t signal(int signum, sighandler_t handler);

void catch_sig(int num)
{
    printf("cat %d sig\n",num);
}

int main()
{

    signal(SIGALRM,catch_sig);
    struct itimerval myit = {{3,0},{5,0}};//第一次等待5s，之后每隔3s
    setitimer(ITIMER_REAL,&myit,NULL);

    while(1){
        printf("who can kill me!\n");
        sleep(1);
    }


    return 0;
}

