/* 9b 
./a.out source.txt*/
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char buff[21];

    int n = read(fd, buff, 20);
    buff[n]='\0';
    printf("First 20 characters\n %s \n", buff);
    lseek(fd, 10, SEEK_SET);

    n = read(fd, buff, 20);
    buff[n]='\0';
    printf("Characters from 10th byte \n %s \n", buff);
    lseek(fd, 10, SEEK_CUR);

    n = read(fd, buff, 20);
    buff[n]='\0';
    printf("Characters from current \n %s \n", buff);
    n = lseek(fd, 0, SEEK_END);
    
    printf("File Size %d \n", n);
    return 0;
}