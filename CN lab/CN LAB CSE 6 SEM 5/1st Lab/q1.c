// 1. Write a C program to swap the content of 2 variables using a pointer.

#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    if(argc<2)
        printf("No argument passed through command line\n");
    int a=atoi(argv[1]), b=atoi(argv[2]);
    int *ptra=&a, *ptrb=&b;
    int temp=*ptra;
    *ptra=*ptrb;
    *ptrb=temp;
    printf("After swapping:\na=%d, b=%d",*ptra,*ptrb);
    return 0;
}