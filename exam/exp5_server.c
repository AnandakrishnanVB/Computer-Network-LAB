#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 20

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t len = sizeof(address);
    int n, matrix[MAX][MAX];
    char result[100];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 4);

    printf("Waiting for server connection.\n");
    new_socket = accept(server_fd, (struct sockaddr *)&address, &len);
    read(new_socket, &n, sizeof(n));
    read(new_socket, matrix, sizeof(matrix));

    int diagonal = 1, lower = 1, upper = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && matrix[i][j] != 0)
                upper = 0;
            if (i < j && matrix[i][j] != 0)
                lower = 0;
            if (i != j && matrix[i][j != 0])
                diagonal = 0;
        }
    }
    if (diagonal)
    {
        strcpy(result, "Diagonal matrix");
    }
    else if (upper)
    {
        strcpy(result, "Upper triangle matrix");
    }
    else if (lower)
    {
        strcpy(result, "Lower triangle matrix");
    }
    else
    {
        strcpy(result, "Neither upper nor lower nor diagonal");
    }
    write(new_socket, result, sizeof(result));
    printf("Matrix Type Sent to Client: %s\n", result);
    close(new_socket);
    close(server_fd);
}