// Normal

#include<stdio.h>
#include<setjmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
jmp_buf buf;
void f2()
{
        longjmp(buf,1);
}
void f1(int rv,int vv)
{
        printf("In f1()\n");
        printf("rv = %d, vv = %d\n",rv,vv);
        f2();
}
int main()
{

        register int rv=10;
        volatile int vv=20;
        if((setjmp(buf))!=0)
        {
                printf("after long rv = %d , vv = %d\n",rv,vv);
                exit(0);
        }
        rv=100;
        vv=200;
        f1(rv,vv);
        return 0;
}