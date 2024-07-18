/* 10b ./a.out */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int status;
    pid_t pid1,pid2;
    pid1 = fork();
    pid2 = fork();
    if(pid1==0)
    {
        printf("First pid:%d\n", getpid());
        sleep(2);
        exit(0);
    }
    if(pid2==0)
    {
        printf("Second pid:%d\n", getpid());
        sleep(4);
        exit(0);
    }
    wait(&status);
    printf("First wait\n");
    sleep(1);
    waitpid(pid2, &status,0);
    printf("Second wait\n");
    return 0;
}