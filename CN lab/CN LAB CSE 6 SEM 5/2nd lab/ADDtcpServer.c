/*Write a socket program to add two numbers.*/

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 3786
int main() {
int sd, newSd, cliLen, n, num1, num2, sum;
struct sockaddr_in cliAddr, servAddr; 
char line[MAX_MSG], line1[MAX_MSG], line2[MAX_MSG];
bzero((char*)&servAddr, sizeof(servAddr));
servAddr.sin_family = AF_INET;
servAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
servAddr.sin_port = htons(SERVER_PORT);
sd = socket(AF_INET,SOCK_STREAM, 0);
printf("Successfully created stream socket \n");
//pid_t childpid;
bind(sd, (struct sockaddr *)&servAddr, sizeof(servAddr));
printf("Bound local port successfully \n");
socklen_t addr_size;
listen(sd, 5);
while(1) {
printf("Waiting for client connection on port TCP %u\n",SERVER_PORT);
cliLen = sizeof(cliAddr);
newSd = accept(sd, (struct sockaddr *)&cliAddr, &addr_size);
printf("Received connection from host from host[IP %s,TCP port %d]\n", inet_ntoa(cliAddr.sin_addr),ntohs(cliAddr.sin_port));
do
{
memset(line,0x0,MAX_MSG);
n = recv(newSd, line, MAX_MSG, 0);
num1 = atoi(line);
n = recv(newSd, line, MAX_MSG, 0);
num2 = atoi(line);
sum = num1 + num2;
sprintf(line1,"%d",sum);
printf("Received from host[IP %s,TCP port %d]: %s\n", inet_ntoa(cliAddr.sin_addr),ntohs(cliAddr.sin_port),line1);
send(newSd,line1,strlen(line1) + 1,0);
}
while(abs(strcmp(line, "Quit")));
printf("Closing connection with host [IP %s,TCP port %d]\n", inet_ntoa(cliAddr.sin_addr),ntohs(cliAddr.sin_port));
close(newSd);
}
}
