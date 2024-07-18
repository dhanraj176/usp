/* 3b
usage: ./a.out
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<time.h>
int main()
{
  struct dirent *dir;
  struct stat filestat;
  DIR *dp;
  dp = opendir(".");
  if(dp)
  {
    while(dir = readdir(dp))
    {
      stat(dir->d_name,&filestat);
      printf("File Name : %s\n", dir->d_name);
      printf("File size : %ld\n", filestat.st_size);
      printf("File inode : %ld\n", filestat.st_ino);
      printf("User id of file owner : %u\n", filestat.st_uid);
      printf("Group id of file owner : %u\n", filestat.st_gid);
      printf("File links : %ld\n", filestat.st_nlink);
    }
  }
  return 0;
}
