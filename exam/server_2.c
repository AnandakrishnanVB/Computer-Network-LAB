#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addr_len = sizeof(address);

    int message;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 5);
    printf("Waiting for client..\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addr_len);

    printf("Client connected.\n");
    read(new_socket, &message, sizeof(message));
    printf("Client said:%d", message);

    int result = message * 10;

    write(new_socket, &result, sizeof(result));

    close(new_socket);
    close(server_fd);
    return 0;
}