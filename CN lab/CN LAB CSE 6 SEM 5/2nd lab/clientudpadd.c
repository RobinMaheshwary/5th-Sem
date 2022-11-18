#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	int snd, recv, temp;
	int buff[2];

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);


	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;	// ipv4
	server_addr.sin_port = htons(8080);	// port no.
	server_addr.sin_addr.s_addr = INADDR_ANY;	// ip address

	printf("\nEnter num1: ");
	scanf("%d", &buff[0]);
	

	snd = sendto(sockfd, &buff, strlen((char *)buff), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
	
	if(snd == -1)	// sending num1
		printf("\nError: Msg not sent\n");
	else
		printf("\nMessage successfully sent!\n");
		
	printf("\nEnter num2: ");
	scanf("%d", &buff[0]);
	
	// sending num2
	snd = sendto(sockfd, &buff, strlen((char *)buff), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

	if(snd == -1)	// send check
		printf("\nError: Msg not sent\n");
	else
		printf("\nMessage successfully sent!\n");
	
	recv = recvfrom(sockfd, &buff, sizeof(buff), 0,(struct sockaddr*)&server_addr, &temp);
	
	printf("\nSum as received: %d\n", buff[0]);
	
	close(sockfd);
	
	return 0;
}