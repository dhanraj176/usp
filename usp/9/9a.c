

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
       mode_t newmask=022;
       mode_t oldmask;
       oldmask=umask(newmask);
       printf("old mask %03o and new mask :%03o\n",oldmask,newmask);
       mode_t new_mode=0666;
       chmod("t1.txt",new_mode)
       printf("change the permision of file to %03o\n",new_mode);
}