// ./a.out source.txt
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc , char* argv[])
{
  pid_t pid;
  int fd=open(argv[1],O_RDONLY);
  char buf[100];

  pid=fork();

  if(pid<0){
    printf("error in creation");
  }
  else if(pid==0)
  {
    int bytesread=read(fd,buf,5);
     buf[bytesread]='\0';
     printf("child read %s\n",buf);
  }
  else{
    wait(NULL);
    int bytesread=read(fd,buf,5);
     buf[bytesread]='\0';
     printf("child read %s\n",buf);
  }
  close(fd);
  return 0 ;
}