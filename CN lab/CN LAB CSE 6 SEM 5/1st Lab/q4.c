/* 4. Write a C Program to enter a number and store the number across the
following structure and print the content of each member of the structure.
Then aggregate each member of the structure to form the original number and
print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
*/

#include <stdio.h>
#include <stdlib.h>
struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};
int main()
{
    printf("Enter a 4 digit number: ");
    int num;
    scanf("%d",&num);
    struct pkt c;
    int first=num/1000;
    c.ch1=first+'0';
    c.ch3=num%10+'0';
    int t=num-first*1000;
    t/=10;
    c.ch2[1]=t%10+'0';
    t/=10;
    c.ch2[0]=t+'0';
    printf("\nStructure:\nch1=%c\nch2=%c%c\nch3=%c\n",c.ch1,c.ch2[0],c.ch2[1],c.ch3);
    int o[4];
    o[0]=c.ch1-'0';
    o[1]=c.ch2[0]-'0';
    o[2]=c.ch2[1]-'0';
    o[3]=c.ch3-'0';
    int original=0;
    for(int i=0; i<=3; i++)
    {
        original*=10;
        original+=o[i];
    }
    printf("\nOriginal number: %d\n",original);
    return 0;
}