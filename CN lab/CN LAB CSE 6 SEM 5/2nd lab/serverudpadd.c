#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main() {
	int temp, nums[2];
	char buff[100];


	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in server_addr, client_addr;
	
	server_addr.sin_family = AF_INET;	// ipv4
	server_addr.sin_port = htons(8080);	// port
	server_addr.sin_addr.s_addr = INADDR_ANY;	// ip address
	

	int b = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (b != 0) printf("\nError binding!\n");
	else printf("\nServer running\n");
	

	int recv = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&client_addr, &temp);
	
	printf("\nMsg received: \tnum1: %d", buff[0]);
	nums[0] = buff[0];	
		

	recv = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&client_addr, &temp);
	
	printf("\nMsg received: \tnum2: %d\n", buff[0]);
	nums[1] = buff[0];

	int sum = nums[0] + nums[1];

	
	int snd;
	snd = sendto(sockfd, &sum, sizeof(sum), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
	
	if (snd < 0) printf("\n!error sending!\n");
	else printf("\nsent successfully\n");
	
	return 0;

}