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
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Entert the number:");
    scanf("%d", &num);

    if (sendto(server_fd, &num, sizeof(num), 0,
               (struct sockaddr *)&server_addr,
               sizeof(server_addr)) < 0)
    {
        perror("Send failed");
    }

    socklen_t len = sizeof(client_addr);
    recvfrom(server_fd, &num, sizeof(num), 0, (struct sockaddr *)&client_addr, &len);

    printf("Square is %d\n", num);
    close(server_fd);
}