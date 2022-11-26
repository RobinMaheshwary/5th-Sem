#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 1024
#define PORT 8080

int main()
{
     int sockfd;
     struct sockaddr_in servaddr, cli;

     sockfd = socket(AF_INET, SOCK_DGRAM, 0);
     if (sockfd == -1)
     {
          printf("socket creation failed.\n");
          exit(0);
     }

     memset(&servaddr, 0, sizeof(servaddr));

     
     servaddr.sin_family = AF_INET;
     servaddr.sin_port = htons(PORT);
     servaddr.sin_addr.s_addr = INADDR_ANY;

     char buffer[MAX];
     printf("Send to the server: \n");
     scanf("%[^\n]s", buffer);
     sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));


    recv(sockfd, buffer, MAX, 0);
    printf("Server: %s", buffer);
    
     close(sockfd);
}