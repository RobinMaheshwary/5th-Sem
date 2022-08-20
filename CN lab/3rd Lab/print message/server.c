#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    char *ip = "127.0.0.1";
    int port = 5577;

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024] = "\0";
    int n;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("SOCKET ERROR\n\n");
        exit(1);
    }
    printf("TCP server socket created\n\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        perror("BIND ERROR\n\n");
        exit(1);
    }
    printf("TCP server socket binded to port no. :%d \n\n", port);

    listen(server_sock, 1);
    printf("Listning...\n");

    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
    printf("CLIENT connected\n\n");

    bzero(buffer, 1024);
    strcpy(buffer, "hello client");
    send(client_sock, buffer, sizeof(buffer), 0);
    printf("Server :%s\n\n", buffer);

    bzero(buffer, 1024);
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n\n", buffer);

    // printf("add message from client")

    close(server_sock);
    printf("\n\nclient disconnected");

    return 0;
}