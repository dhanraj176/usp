// ./a.out
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
     struct stat sfile;
     stat("test.txt",&sfile);

     printf("Inode number:%ld\n",sfile.st_ino);
     printf("size :%ld\n",sfile.st_size);
     printf("dis number:%ld\n",sfile.st_dev);
     printf("user number:%d\n",sfile.st_uid);
     printf("link number:%ld\n",sfile.st_nlink);
}

