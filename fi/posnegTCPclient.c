#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAX 500

int main()
{
    int server_fd, num;
    char buffer[MAX];
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Socket creation failed");
        return 1;
    }
    printf("Socket created successfully\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Enter the number:");
    scanf("%d", &num);

    int c = connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (c < 0)
    {
        perror("Connect failed\n");
        return 1;
    }

    write(server_fd, &num, sizeof(num));
    read(server_fd, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    close(server_fd);
}