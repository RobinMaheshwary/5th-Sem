#include <stdio.h>
#include <stdlib.h>
int check_endianness()
{
    int x=1;
    char *c=(char*)&x;
    return (int)*c;
}
int convert_endianness(int num)
{
    int byte0, byte1, byte2, byte3;
    byte0 = (num & 0x000000FF)>>(0*8);
    byte1 = (num & 0x0000FF00)>>(1*8);
    byte2 = (num & 0x00FF0000)>>(2*8);
    byte3 = (num & 0xFF000000)>>(3*8);
    printf("Content of each byte location:\nByte 0 = %x\n", byte0);
    printf("Byte 1 = %x\n", byte1);
    printf("Byte 2 = %x\n", byte2);
    printf("Byte 3 = %x\n", byte3);

    byte0<<=(3*8);
    byte1<<=(2*8);
    byte2<<=(1*8);
    byte3<<=(0*8);
    int result =(byte0 | byte1 | byte2 | byte3);
    return result;
}
int main()
{
    if(check_endianness())
        printf("Host Machine is in Little Endian\n");
    else
        printf("Host Machine is in Big Endian\n");
    int bigEndian=0x12345678;
    int littleEndian=0x78563412;
    printf("\nBig Endian: 0x%x\n",bigEndian);
    int result1=convert_endianness(bigEndian);
    printf("Big Endian to Little Endian: 0x%x\n",result1);
    printf("\nLittle Endian: 0x%x\n",littleEndian);
    int result2=convert_endianness(littleEndian);
    printf("Little Endian to Big Endian: 0x%x\n",result2);
    return 0;
}