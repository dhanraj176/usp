// Open 2 terminals 
// Terminal 1 Run  press enter 
// Terminal 2 Run  press enter


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
        struct flock fvar;
        int fd=open("example.txt",O_RDWR);
        fvar.l_type=F_WRLCK;
        fvar.l_len=100;
        fvar.l_whence=SEEK_END;
        fvar.l_start=-100;
        printf("Click enter to lock");
        getchar();
        printf("Locking");
        if((fcntl(fd,F_SETLK,&fvar))==-1);
        {
                fcntl(fd,F_GETLK,&fvar);
                printf("Process that has locked : %d\n",fvar.l_pid);
                return -1;
        }
        printf("Locked!");
        char b[51];
        lseek(fd,-50,SEEK_END);
        read(fd,b,50);
        b[51]='\0';
        printf("Content: %s\n",b);
        fvar.l_type = F_UNLCK;
        fcntl(fd,F_SETLK,&fvar);
        printf("Unlocked!");
}