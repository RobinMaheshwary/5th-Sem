#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#include<strings.h>
#include <arpa/inet.h>

void main()
{
int b,sockfd,sin_size,con,n,len;

char res1,res2,res3;
int op1,op2,op3;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");

struct sockaddr_in servaddr;

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6006;

sin_size = sizeof(struct sockaddr_in);
if((con=connect(sockfd,(struct sockaddr *) &servaddr, sin_size))==0); //initiate a connection on a socket
printf("connect sucessful\n");
printf("Enter marks:\n");
scanf("%d %d %d", &op1, &op2, &op3);
write(sockfd,&op1,sizeof(op1));
write(sockfd,&op2,sizeof(op2));
write(sockfd,&op3,sizeof(op3));
read(sockfd,&res1,sizeof(res1));
printf("grade=%c\n",res1);
read(sockfd,&res2,sizeof(res2));
printf("grade=%c\n",res2);
read(sockfd,&res3,sizeof(res3));
printf("grade=%c\n",res3);  
close(sockfd);
}