#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc,char *argv[])
{
        for(int i=0;i<argc;i++)
        {
                printf("arg[%d] = %s\n",i,argv[i]);
        }

}
