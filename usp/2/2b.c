/* 2b
usage: ./a.out
*/
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<time.h>
int main()
{
struct dirent *dir;
 DIR *dp;
 dp=opendir(".");
 if(dp)
 {
  while(dir=readdir(dp))
  {
    printf("%s \n",dir->d_name);
  }
 }


  return 0;
}
