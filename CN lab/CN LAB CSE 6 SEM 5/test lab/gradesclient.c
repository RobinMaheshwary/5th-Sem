#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define CLIENT_ADDR "127.0.0.1"
#define SERVER_PORT 3786
#define CLIENT_PORT 8229

int main() {
int sd, rc, i,n;
struct sockaddr_in clientAddr,servAddr;
char line[MAX_MSG];
bzero((char *)&servAddr,sizeof(servAddr));
servAddr.sin_family = AF_INET;
servAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
servAddr.sin_port = htons(SERVER_PORT);
bzero((char *)&clientAddr, sizeof(clientAddr));
clientAddr.sin_family = AF_INET;
clientAddr.sin_addr.s_addr = INADDR_ANY;
clientAddr.sin_port = htons(0);
sd = socket(AF_INET, SOCK_STREAM, 0);
printf("Successfully created stream socket \n");
bind(sd, (struct sockaddr *) &clientAddr, sizeof(clientAddr));
printf("Bound local port successfully\n");
connect(sd, (struct sockaddr *) &servAddr, sizeof(servAddr));
printf("Connected to server successfully \n");
do {
printf("Enter 1st grade: ");
scanf("%s",line);
send(sd,line,strlen(line) + 1,0);
printf("Data sent (%s)\n",line);
printf("Enter 2nd grade : ");
scanf("%s",line);
send(sd,line,strlen(line) + 1,0);
printf("Enter 3rd grade : ");
scanf("%s",line);
send(sd,line,strlen(line) + 1,0);
printf("Data sent (%s)\n",line);
n = recv(sd,line, MAX_MSG,0);

printf("Received from server %s\n",line);
}
while(strcmp(line,"Quit"));
printf("Closing connection with the server\n");
close(sd);
}
