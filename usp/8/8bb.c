// cc -o code 8bb.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n = access(argv[1], F_OK);
    
    if(n==0)
    {
        printf("\nFile can be accessed\n");
    }
    else
    {
        printf("File cannot be accessed");
    }
    
    return 0;
}