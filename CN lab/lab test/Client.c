#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
#include<strings.h>
#include <arpa/inet.h>

//#define buffsize  150
void main()
{
int b,sockfd,sin_size,con,n,len;
//char buff[256];
char res;
int op1,op3,op4;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");
//printf("%d\n", sockfd);
struct sockaddr_in servaddr;

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6006;

sin_size = sizeof(struct sockaddr_in);
if((con=connect(sockfd,(struct sockaddr *) &servaddr, sin_size))==0); //initiate a connection on a socket
printf("connect sucessful\n");
printf("Enter marks:\n");
scanf("%d %d %d", &op1, &op3, &op4);
write(sockfd,&op1,sizeof(op1));
write(sockfd,&op3,sizeof(op3));
write(sockfd,&op4,sizeof(op4));
read(sockfd,&res,sizeof(res));
printf("grade=%c\n",res);  
close(sockfd);
}