#include <sys/types.h>          
#include <sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <arpa/inet.h>

#define myport 8080

int main(){
    int sock_fd = socket(PF_INET, SOCK_STREAM,0);
     if(sock_fd < 0){
        perror("ERROR");
        exit(1);}
      else 
      {printf("hello");}
     
     
     struct sockaddr_in addrport;
     addrport.sin_family = AF_INET;
     addrport.sin_port = htons(myport);
     addrport.sin_addr.s_addr = htonl(INADDR_ANY);
     
     int b = bind(sock_fd, (struct sockaddr *) &addrport, sizeof(addrport)); 
        if(b < 0){
        perror("ERROR");
        exit(1);}
        else 
      printf("hello");

      
     







    return 0;
}