// compile and run normally after doing echoall
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
        char *env_items[]={"USER=unknown","PATH=/tmp",NULL};
        pid_t pid=fork();
        if(pid==0)
        {
                printf("child is executing");
                execle("./echoall","echoall","myarg1","myarg2",(char *)NULL,env_items);
        }
        waitpid(pid,NULL,0);
        printf("parent time");
        execlp("./echoall","echoall","firstarg",(char *)NULL);

}