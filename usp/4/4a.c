// ./a.out <Exisiting file> <New File>
// ./a.out Exisiting file New File1 New File 2

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int  main ( int argc, char*argv[])
{
    if(argc==3)
    {
        link(argv[1],argv[2]);
        printf("hard link is created ");
    }
    else if(argc==4)
    {
        symlink(argv[2],argv[3]);
        printf("soft link is created");
    }
    return 0 ;
}