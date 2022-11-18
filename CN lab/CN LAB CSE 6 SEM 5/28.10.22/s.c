// write a udp multi client program where server sent current time and date to  two clientsclients.

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define PORT 5555

int main(){
    int sockfd, ret;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    time_t t;
    struct tm *tmp;
    char MY_TIME[50];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Server Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        printf("[-]Error in binding.\n");
        exit(1);
    }
    printf("[+]Bind to port %d", 4444);

    while(1){
        t = time(NULL);
        tmp = localtime(&t);
        strftime(MY_TIME, sizeof(MY_TIME), "%Y-%m-%d %H:%M:%S", tmp);
        sendto(sockfd, MY_TIME, strlen(MY_TIME), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        printf("Current Time: %s", MY_TIME);
        sleep(1);
        

}
