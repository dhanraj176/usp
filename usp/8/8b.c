/* 8b ./a.out */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
   pid_t pid ,ppid;
   int status;
   ppid=getpid();
   pid=fork();
   if(pid==-1)
   {
    printf("error");
   }
   else if(pid==0)
   {
    pid_t cpid=getpid();
    printf("Child processing with pid %d\n",cpid);
    execl("./code","code","sample.txt",(char*)NULL);
   }
   else{
    printf("\npaarent is process : %d",ppid);
    waitpid(pid,&status,0);
    printf("\nchild process exicited %d\n",pid);
   }
}

