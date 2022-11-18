#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#include <arpa/inet.h>
void main()
{
int b,sockfd,connfd,sin_size,l,n,len;
int op1,op2,op3;
char res1,res2,res3;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");  

struct sockaddr_in servaddr;              
struct sockaddr_in clientaddr;

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6006;

if((bind(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)))==0)
printf("bind sucessful\n");  
if((listen(sockfd,5))==0) //listen for connections on a socket
printf("listen sucessful\n");
sin_size = sizeof(struct sockaddr_in);
if((connfd=accept(sockfd,(struct sockaddr *)&clientaddr,&sin_size))>0);
printf("accept sucessful\n");
read(connfd,&op1,sizeof(op1));
read(connfd,&op2,sizeof(op2));
read(connfd,&op3,sizeof(op3));
if(op1>=90)
   res1='O';
   else if(op1<=90 && op1>=80 )
   res1='E';
   else if(op1<80 && op1>=70)
   res1='A';
   else if(op1<70 && op1>=60 )
   res1='B';
    else if(op1<60 && op1>=50 )
    res1='C';
   else if(op1<50)
   res1='F';
write(connfd,&res1,sizeof(res1)); 

if(op2>=90)
   res2='O';
   else if(op2<90 && op2>=80 )
   res2='E';
   else if(op2<80 && op2>=70)
   res2='A';
   else if(op2<70 && op2>=60 )
   res2='B';
    else if(op2<60 && op2>=50 )
    res2='C';
   else if(op2<50)
   res2='F';
write(connfd,&res2,sizeof(res2)); 

if(op1>=90)
   res3='O';
   else if(op3<90 && op3>=80 )
   res3='E';
   else if(op3<80 && op3>=70)
   res3='A';
   else if(op3<70 && op3>=60 )
   res3='B';
    else if(op3<60 && op3>=50 )
    res3='C';
   else if(op3<50)
   res3='F';
write(connfd,&res3,sizeof(res3)); 

printf("grades sent\n");

close(sockfd);
}