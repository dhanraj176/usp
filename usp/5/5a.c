// Normal
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<utime.h>

int main()
{
        struct stat mystat;
        struct utimbuf newtimes;
        stat("source.txt",&mystat);
        newtimes.actime = mystat.st_atime;
        newtimes.modtime = mystat.st_mtime;
        utime("test.txt",&newtimes);
        return 0;
}
