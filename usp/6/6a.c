/* 6a
usage: ./a.out source.txt
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int f1,f2;
  char buf[100];
  f1=open("example.txt",O_RDWR);
  f2=open("sample.txt",O_RDWR);
  f2=dup2(f1,f2);
  read(f1,buf,5);
  lseek(f2,0,SEEK_END);
  write(f2,buf,5);
  close(f1);
  close(f2);
  return 0;
}