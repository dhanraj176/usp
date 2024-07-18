/* 1a 
usage: ./a.out source.txt
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc , char* argv[])
{
    char buf;
    int n , fd=open(argv[1],O_RDONLY);

   int fsize=lseek(fd,0,SEEK_END);

    for(int i=fsize-1;i>=0;i--)
    {
           lseek(fd,i,SEEK_SET);
           n=read(fd,&buf,1);
           printf("%c",buf);
    }
    close(fd);
    printf("\n");
}