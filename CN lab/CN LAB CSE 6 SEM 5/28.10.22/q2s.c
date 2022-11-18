#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
int rever(int n){
	int rev=0;
	while(n>0){
		rev=rev*10+n%10;
		n/=10;
	}
	return rev;
}
int main()
{
    int sockfd, connfd1,connfd2, len;
    char buff[MAX];
    struct sockaddr_in servaddr, cli;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <= -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) < 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    if ((listen(sockfd, 3)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    len = sizeof(cli);
    int a,b;

        if ((connfd1 = accept(sockfd, (SA *)&cli, &len)) < 0)
        {
            printf("server accept failed...\n");
            exit(0);
        }
        if ((connfd2 = accept(sockfd, (SA *)&cli, &len)) < 0)
        {
            printf("server accept failed...\n");
            exit(0);
        }
                read(connfd1, &a, sizeof(a));
                read(connfd2, &b, sizeof(b));    
                a=rever(a);
                b=rever(b); 
		write(connfd2, &a, sizeof(a));     
		write(connfd1, &b, sizeof(b));
		printf("%d %d",a,b);
    close(sockfd);
}