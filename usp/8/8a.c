/* 8a ./a.out source.txt*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int n , type ;
struct stat file;
n=stat(argv[1],&file);
type=file.st_mode;
    if(S_ISREG(type))
    {
        printf("Regular\n");
    }
    else if(S_ISDIR(type))
    {
        printf("Directory\n");
    }
    else if(S_ISCHR(type))
    {
        printf("Character Special");
    }
    else if(S_ISBLK(type))
    {
        printf("Block Special");
    }
    else if(S_ISFIFO(type))
    {
        printf("Fifo");
    }
    else if(S_ISLNK(type))
    {
        printf("Symbolic Link");
    }
    else if(S_ISSOCK(type))
    {
        printf("Socket");
    }
    else
    {
        printf("Unknown Mode");
    }
    return 0;
}

