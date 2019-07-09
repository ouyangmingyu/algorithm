#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{


    //先备份现场
    int outfd = dup(1);
    //先做重定向
    int fd = open("world",O_WRONLY|O_CREAT,0666);
    dup2(fd,1);//将标准输出重定向到fd对应的文件
    printf("hello world\n");

    //需要来一次刷新下
    fflush(stdout);

    //需要恢复1 重新对应 标准输出
    
    dup2(outfd,1);

    printf("hello world\n");
    close(fd);
    return 0;
}
