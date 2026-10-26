#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX 20

int main()
{
    int socket_fd;
    struct sockaddr_in address;
    int n, matrix[MAX][MAX];
    char result[100];
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    connect(socket_fd, (struct sockaddr *)&address, sizeof(address));
    printf("Enter the order of matrix:");
    scanf("%d", &n);
    srand(time(0));
    printf("Generated matrix.\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 50 + 1;
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    write(socket_fd, &n, sizeof(n));
    write(socket_fd, matrix, sizeof(matrix));
    read(socket_fd, result, sizeof(result));
    printf("Matrix received from client:%s\n", result);
    close(socket_fd);
}