/* 3. Write a C program to extract each byte from a given number and store
them in separate character variables and print the content of those variables. 
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num=0x12345678; //4 byte integer
    char byte0, byte1, byte2, byte3;
    byte0 = ((num >> (0*8))& 0xFF);;
    byte1 = ((num >> (1*8)) & 0xFF);
    byte2 = ((num >> (2*8)) & 0xFF);
    byte3 = ((num >> (3*8)) & 0xFF);
    printf("Byte 0 = %x\n", byte0);
    printf("Byte 1 = %x\n", byte1);
    printf("Byte 2 = %x\n", byte2);
    printf("Byte 3 = %x\n", byte3);
    return 0;
}