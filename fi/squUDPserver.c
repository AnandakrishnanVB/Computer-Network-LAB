#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000

int main()
{
    int server_fd, num;
    struct sockaddr_in server_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Server is up..\n");
    socklen_t len = sizeof(client_addr);
    recvfrom(server_fd, &num, sizeof(num), 0, (struct sockaddr *)&client_addr, &len);
    printf("%d", num);
    num = num * num;

    sendto(server_fd, &num, sizeof(num), 0, (struct sockaddr *)&client_addr, len);
    close(server_fd);
}