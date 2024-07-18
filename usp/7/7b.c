/* 7b
usage: ./a.out source.txt dest.txt
*/
#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
  char buff[400];
  int sfd, dfd;
  ssize_t br, bw;
  sfd = open(argv[1], O_RDONLY);
  dfd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
  while((br=read(sfd, buff, 400))>0)
  {
    bw = write(dfd, buff, br);
  }
  return 0;
}