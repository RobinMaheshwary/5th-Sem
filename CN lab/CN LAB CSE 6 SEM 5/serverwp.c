#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(){

    int sockfd, bd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port=htons(8000);
    myaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    bd=bind(sockfd,(struct sockaddr *)&myaddr &sizeof(myaddr));

    if(bd == 0){
        printf("\n Successfully executed\n");}

    else
    perror("\n some error\n");
    close(sockfd);

    return 0;
    }

