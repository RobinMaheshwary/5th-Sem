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

    int sock;
    struct sockaddr_in addr;
    socklen_t addr_size;
    char buffer[1024] = "\0";
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("SOCKET ERROR\n\n");
        exit(1);
    }
    printf("TCP server socket created\n\n");

    addr.sin_family = AF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = inet_addr(ip);

    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    printf("connected to server\n");

    bzero(buffer, 1024);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server :%s\n\n", buffer);

    bzero(buffer, 1024);
    strcpy(buffer, "hello server");
    send(sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n\n", buffer);
    return 0;
}