#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main()
{
    int serverfd;
    char buffer[MAX];
    struct sockaddr_in server_addr;
    serverfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Enter the string:");
    fgets(buffer, MAX, stdin);

    sendto(serverfd, buffer, MAX, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    socklen_t len = sizeof(server_addr);
    int n = recvfrom(serverfd, buffer, MAX - 1, 0, (struct sockaddr *)&server_addr, &len); // This returns the number of bytes received.
    buffer[n] = '\0';
    printf("%s\n", buffer);
    close(serverfd);
}