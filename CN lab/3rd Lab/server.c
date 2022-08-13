#include <sys/types.h>          
#include <sys/socket.h>
#include<stdio.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
int sockfd,bd;
int a,b;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd>=0)
printf("Succesfully done %d\n",sockfd);
else
printf("ERROR");

struct sockaddr_in myaddr;
myaddr.sin_family=AF_INET;
myaddr.sin_port=htons(8000);   /* port */
myaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

bd=bind(sockfd,(struct sockaddr *)&myaddr,sizeof(myaddr));

if(bd>=0)
printf("Succesfully done %d\n",bd);
else
printf("ERROR");






close(sockfd);

return 0;

}