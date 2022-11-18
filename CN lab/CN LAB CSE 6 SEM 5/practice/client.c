// Write a  in c using tcp where client sends an array of 10 elements and at server side you have to find the largest element in array and send largest element to client

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int s,r,recb,sntb,x,ns,a=0,arr[10];
    printf("Enter the elements: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }

    struct sockaddr_in server,client;
    char buff[50];
    s=socket(AF_INET,SOCK_STREAM,0);
    if(s==-1){
        printf("Socket creation error");
        exit(0);
    }
    printf("Socket created");

    server.sin_family=AF_INET;
    server.sin_port=htons(5588);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    r=connect(s,(struct sockaddr*)&server,sizeof(server));
    if(r==-1){
        printf("Connection error");
        exit(0);
    }
    printf("Socket connected");


    sntb=send(s,arr,sizeof(arr),0);
    if(sntb==-1){
        close(s);
        exit(0);
    }

    printf("Data sent");

    recb=recv(s,&a,sizeof(a),0);
    if(recb==-1){
        printf("Recieving error");
        close(s);
        exit(0);
    }
    printf("Data recieved");

    printf("Largest element is: %d",a);
    close(s);
    
}

