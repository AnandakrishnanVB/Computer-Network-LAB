#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080
#define SIZE 1024
int main()
{
    int server_fd;
    struct sockaddr_in server_addr;
    char filename[100];
    char buffer[SIZE];
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Enter the filename:");
    scanf("%s", filename);
    write(server_fd, filename, sizeof(filename) + 1);
    read(server_fd, buffer, sizeof(filename));
    printf("%s\n", buffer);
    close(server_fd);
}