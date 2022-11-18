#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <math.h>#
#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 3786


    main()
{
    int sd, newSd, cliLen, n, num1, num2, sum;
    struct sockaddr_in cliAddr, servAddr;
    char line[MAX_MSG], line1[MAX_MSG], line2[MAX_MSG];
    bzero((char *)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    servAddr.sin_port = htons(SERVER_PORT);
    sd = socket(AF_INET, SOCK_STREAM, 0);
    printf("successfully created stream socket \n");
    pid_t childpid;
    bind(sd, (struct sockaddr *)&servAddr, sizeof(servAddr));
    printf("bound local port successfully\n");
    socklen_t addr_size;
    listen(sd, 5);
    while (1)
    {
        printf("waiting for client connection on port TCP %u\n", SERVER_PORT);
        cliLen = sizeof(cliAddr);
        newSd = accept(sd, (struct sockaddr *)&cliAddr, &addr_size);
        printf("received connection from host [IP %s ,TCP port %d]\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));
        if ((childpid = fork()) == 0)
        {
            close(sd);
        }
    }
}