#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<syslog.h>
#include<stdlib.h>
#include<sys/stat.h>
void daemon_create()
{
        pid_t pid=fork();

        if(pid>0)
        {
                exit(0);
        }
        setsid();
        umask(0);
        chdir("/");
        open("/dev/null",O_RDONLY);
        open("/dev/null",O_WRONLY);
        open("/dev/null",O_RDWR);
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
}
int main()
{
        daemon_create();
    
}
