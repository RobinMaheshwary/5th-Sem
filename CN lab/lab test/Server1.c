#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
  int sockfd;
  sockfd = socket(AF_INET,SOCK_DGRAM,0);
  if(sockfd<0)
  {
    printf("Socket Failure\n");
    exit(1);
    }
    struct sockaddr_in server_addr,client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7980);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int bindfd;
    bindfd = bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    if(bindfd<0)
    {
      printf("Bind Failure");
      exit(1);
    }
    char buff[100];
    socklen_t addr_size;
    addr_size = sizeof(client_addr);
    bzero(buff,100);
    recvfrom(sockfd,buff,100,0,(struct sockaddr *)&client_addr,&addr_size);
    printf("CRYPT\n");

    for(int i=0;buff[i] != '\0';i++)
    {
      if(buff[i] == 'a'||buff[i] == 'i'||buff[i] == 'e'||buff[i] == 'o'||buff[i] == 'u')
      {
        buff[i] = buff[i]-32;
      }
    }
    sendto(sockfd,buff,100,0,(struct sockaddr*)&client_addr,sizeof(client_addr));
    printf("DATA CHANGED AND SEND TO CLIENT");


  }