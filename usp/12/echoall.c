// cc -o echoall echoall.c

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[],char * env_items[])
{

        for(int i=0;i<argc;i++)
        {
                printf("argv[%d]=%s\n",i,argv[i]);
        }

        for(int i=0;env_items[i]!=NULL;i++)
        {
                printf("env_items[%d] = %s\n",i,env_items[i]);
        }

}