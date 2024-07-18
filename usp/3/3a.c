/* 3a
usage: ./a.out
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

int main ()
{
  struct dirent *dir;
  DIR *dp;
  struct stat fs;
  dp=opendir(".");

    while((dir=readdir(dp))!=NULL)
    {
      stat(dir->d_name,&fs);
      if(fs.st_size==0)
      {
        printf("removed file is %s\n",dir->d_name);
        remove(dir->d_name);
      }
    }
    return 0 ;

}
