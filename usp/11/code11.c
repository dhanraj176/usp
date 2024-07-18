// cc -o code11 code11.c
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    printf("Sum: %d", n1+n2);
    return 0;
}