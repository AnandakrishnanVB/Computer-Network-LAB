#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8000
#define MAX 100

int main()
{
    int server_fd, client_fd, num;
    char buffer[MAX];
    struct sockaddr_in server_addr, client_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_fd, 5);
    printf("Server is up..\n");
    socklen_t len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);

    read(client_fd, &num, sizeof(num));
    if (num > 0)
    {
        strcpy(buffer, "Positive.");
    }
    else if (num < 0)
    {
        strcpy(buffer, "Negative");
    }
    else
    {
        strcpy(buffer, "Zero");
    }
    write(client_fd, buffer, sizeof(buffer));
    close(server_fd);
}