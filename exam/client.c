#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int client_fd;
    struct sockaddr_in address;

    int value;
    printf("Enter the vlaue:");
    scanf("%d", &value);

    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    address.sin_port = htons(PORT);

    if (connect(client_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("connect");
        return 1;
    }

    write(client_fd, &value, sizeof(value));

    read(client_fd, &value, sizeof(value));

    printf("Server send:%d\n", value);

    close(client_fd);

    return 0;
}