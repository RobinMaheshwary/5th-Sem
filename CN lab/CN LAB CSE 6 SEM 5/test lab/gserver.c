#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
 
  char *ip = "127.0.0.1";
  int port = 5566;
 
  int server_sock_645, client_sock_645;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;
 
  server_sock_645 = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock_645 < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
 
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);
 
  n = bind(server_sock_645, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);
 
  listen(server_sock_645, 5);
  printf("Listening...\n");
 
  while(1){
    addr_size = sizeof(client_addr);
    client_sock_645 = accept(server_sock_645, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");
 
    
    bzero(buffer, 1024);
    strcpy(buffer, "Enter marks in 3 subjects:");
    printf("Server: %s\n", buffer);
    send(client_sock_645, buffer, strlen(buffer), 0);
    
    int marks[3];
    bzero(buffer, 1024);
    recv(client_sock_645, buffer, sizeof(buffer), 0);
    int marks[0]=atoi(buffer);
    printf("Physics Marks: %d\n", marks[0]);
 
    bzero(buffer, 1024);
    recv(client_sock_645, buffer, sizeof(buffer), 0);
    int marks[1]=atoi(buffer);
    printf("Chemistry Marks: %d\n", marks[1]);
    
    bzero(buffer, 1024);
    recv(client_sock_645, buffer, sizeof(buffer), 0);
    int marks[2]=atoi(buffer);
    printf("Mathematics Marks: %d\n", marks[2]);
    
    for(int i=0; i<n; i++)
    {
     char grade;
     if(marks[i]>=91 && marks[i]<=100)
      grade='O';
     else if(marks[i]>=81 && marks[i]<=90)
      grade='E';
 else if(marks[i]>=71 && marks[i]<=80)
  grade='A';
 else if(marks[i]>=61 && marks[i]<=70)
  grade='B';
 else if(marks[i]>=51 && marks[i]<=60)
  grade='C';
 else
  grade='F';
	
 bzero(buffer, 1024);
     strcpy(buffer, grade);
     printf("Server: Grade %d %c\n", (i+1),grade);
     send(client_sock_645, buffer, strlen(buffer), 0);
    
 } 
   
    close(client_sock_645);
    printf("[+]Client disconnected.\n\n");
 
  }
  return 0;
}