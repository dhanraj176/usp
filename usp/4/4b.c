// Compile 4b.c 
// cc -o echoall1 echoall1.c
// to get path of interpreter write pwd in terminal 
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
int main()
{

        pid_t pid=fork();
        if(pid==0)
        {
                execl("interpreter","test","myarg1","myarg2","myarg3",(char *)0);

        }
        else
        {
                wait(NULL);
        }
        return 0;

}
