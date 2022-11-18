// Server side


#include <stdio.h> // header file contains declaration used in input and output e.g. printf() and scanf ()
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h> //the header file contains constants and structures needed for internet domain addresses
#include <sys/socket.h>	//header file contains definitions of structures needed for sockets e.g. defines the sockaddr structure
#include <unistd.h>	
#include <sys/types.h> //contains definitions of nos of data types used in system calls


void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main (int argc,  char * argv[]) //argc = total no parameter //here file name and port no.
{
    if (argc < 2){
    printf("Port no. is missing");
    exit(1);
    }  

    int sockfd, newsockfd, portno, n;
    char buffer [255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen; // sockaddr gives internet address

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) 
    {
        error("Error opening socket");

    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi (argv[1]); // converts strings into integer; argv contains original commands line argument 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd,(struct sockaddr *) &serv_addr , sizeof(serv_addr)<0))
    {
        error("Binding Failed");
    }

    //Listen()
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);//file descriptor = sockfd

    if(newsockfd < 0)
    error("Error on accept");

    while (1)
    {
        bzero(buffer, 255);
        //reading
        n = read(newsockfd, buffer, 255);
        if (n<0)
        {
            error ("error on reading");
        printf("client : %s\n",  buffer);
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        }
        n =write(newsockfd, buffer, strlen(buffer));
        if (n<0);
            error("error on writing");

            int i = strncmp("Bye", buffer, 3);
            if (i==0)
            {
                break;
            }
        close(newsockfd);
        close(sockfd);
        return 0;
        }
    }

    
