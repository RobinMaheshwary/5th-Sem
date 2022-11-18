
do
{
    memset(line, 0x0, MAX_MSG);
    n = recv(newSd, line, MAX_MSG, 0);
    num1 = atoi(line);
    n = recv(newSd, line, MAX_MSG, 0);
    num2 = atoi(line);
    sum = num1 + num2;
    sprintf(line1, "%d", sum);
    printf("received from host [IP %s ,TCP port %d] : %s\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port), line1);
    send(newSd, line1, strlen(line1) + 1, 0);
} while (abs(strcmp(line, "quit")));
printf("closing connection with host [IP %s ,TCP port %d]\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));
}
close(newSd);
