#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000

int main()
{
    int server_fd, num;
    struct sockaddr_in server_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Enter the number:");
    scanf("%d", &num);

    write(server_fd, &num, sizeof(num));

    int fact;
    read(server_fd, &fact, sizeof(fact));
    printf("Factorial is %d\n", fact);
    close(server_fd);
}