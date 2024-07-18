// compile and run after compiling code 11
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    pid_t pid = fork();
    
    if(pid<0)
    {
        fprintf(stderr, "Fork failed");
        exit(-1);
    }
    else if(pid==0)
    {
        execl("./code11", "code11", argv[1], argv[2], (char*)NULL);
    }
    else
    {
        int status;
        waitpid(pid, &status,0);
        printf("Child process exited");
    }
    return 0;
}