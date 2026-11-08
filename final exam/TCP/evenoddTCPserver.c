#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main()
{
    int server_fd, client_fd, num;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_fd, 5);
    printf("server is up..\n");

    socklen_t len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);

    read(client_fd, &num, sizeof(num));
    if (num % 2 == 0)
    {
        strcpy(buffer, "Even");
    }
    else
    {
        strcpy(buffer, "Odd");
    }
    write(client_fd, buffer, MAX);
    close(server_fd);
    close(client_fd);
}