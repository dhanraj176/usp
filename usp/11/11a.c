// Normal
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{

        // DUP
        int fd1=open("t1.txt",O_RDWR);
        int fd2=dup(fd1);
        printf("fd1 = %d, fd2  = %d\n",fd1,fd2);
        write(fd1,"Entry from fd1",14);
        write(fd2,"Entry from fd2",14);
        // DUP2
        int fd11=open("t2.txt",O_RDWR);
        int new_fd = 10;
        int fd22=dup2(fd11,new_fd);
        printf("fd11 = %d , fd22 = %d\n",fd11,fd22);
        write(fd11,"Entry from fd11\n",15);
        write(fd22,"Entry from fd22\n",15);
        close(fd1);
        close(fd2);
        close(fd11);
        close(fd22);
}