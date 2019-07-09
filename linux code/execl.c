#include <unistd.h>
#include <stdio.h>

int main()
{

    //execlp(const char *__file, const char *__arg, ...)
    execlp("lsxx","ls","-l","--color=auto",NULL);

    //不需要判断返回值
    perror("exec err");
    return 0;
}

