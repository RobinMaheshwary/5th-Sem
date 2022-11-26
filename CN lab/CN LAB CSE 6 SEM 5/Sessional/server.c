// WRITE A UDP PROGRAM WHERE 2 CLIENT ( CLIENT 1 AND CLIENT 2
// )CONNECT TO SERVER, EACH CLIENT WILL SHARE THEIR NAME. SEVER
// RECEIVES THE NAME FROM EACH CLIENT AND SERVER SENDS NAME AND IP
// ADDRESS OF CLIENT 1 TO CLIENT 2 AND VICE VERSA.


// Path: server.c

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

     if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
     {
          printf("bind failed.\n");
          exit(0);
     }

     int len, n;
     len = sizeof(cli);

     char buffer[MAX];
     n = recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&cli, &len);
     buffer[n] = '\0';
     printf("Client 1: %s", buffer);
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cli, sizeof(cli));
        printf("IP address of client 1: %s", inet_ntoa(cli.sin_addr));

        n = recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr *)&cli, &len);
        buffer[n] = '\0';
        printf("Client 2: %s", buffer);
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cli, sizeof(cli));
        printf("IP address of client 2: %s", inet_ntoa(cli.sin_addr));

        strcpy(buffer, inet_ntoa(cli.sin_addr));
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cli, sizeof(cli));
        

        close(sockfd);
}
