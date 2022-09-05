#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#include <arpa/inet.h>
void main()
{
int b,sockfd,connfd,sin_size,l,n,len;
int op1,op3,op4;
char res;
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
read(connfd,&op1,sizeof(op3));
read(connfd,&op1,sizeof(op4));
if(op1>=90 || op3>=90 || op4>=90)
   res='A';
   else if(op1>=90 && op1<=80 || op3>=90 && op3<=80 || op4>=90 && op4<=80 )
   res='B';
   else if(op1>=80 && op1<=70 || op3>=80 && op3<=70 || op4>=80 && op4<=70)
   res='c';
   else if(op1>=70 && op1<=60 || op3>=70 && op3<=60 || op4>=70 && op4<=60)
   res='d';
   else
   res='F';
write(connfd,&res,sizeof(res));  
close(sockfd);
}