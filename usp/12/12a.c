#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid, pid2, pid3;
    pid = fork();
    if (pid == 0)
    {
        pid3 = fork();
        if(pid3 == 0)
        {
            sleep(5);
            printf("Child pid is: %d\n", getpid());
            printf("second child, parent pid = %ld\n", (long)getppid());
            exit(0);
        }
        else
        {
            //waitpid(pid3,NULL,0);  THIS IS THE SOLUTION , FIRST EXECUTE THE PROGRAM WITHOUT THIS LINE, THEN WRITE THIS LINE AND EXECUTE
            printf("Child pid: %d\n", getpid());
            exit(0);
        }
    }
    sleep(3);
    pid2 = waitpid(pid, NULL, 0);
    printf("terminated child's pid: %d\n", pid2);
    exit(0);
}
