#include <stdio.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int serverfd;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;

    serverfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Server up..\n");

    socklen_t len = sizeof(client_addr);
    recvfrom(serverfd, buffer, SIZE - 1, 0, (struct sockaddr *)&client_addr, &len);

    for (int i = 0; buffer[i]; i++)
    {
        buffer[i] = toupper(buffer[i]);
    }
    sendto(serverfd, buffer, SIZE + 1, 0, (struct sockaddr *)&client_addr, len);
    printf("Message send.\n");
    close(serverfd);
}
