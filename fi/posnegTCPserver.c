#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAX 500

int main()
{
    int server_fd, client_fd, num;
    char buffer[MAX];
    struct sockaddr_in server_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Socket creation failed");
        return 1;
    }
    printf("Socket created successfully\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        return 1;
    }

    while (1)
    {
        if (listen(server_fd, 5) < 0)
        {
            perror("Listen failed");
            return 1;
        }

        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0)
        {
            perror("Accept failed");
            return 1;
        }
        read(client_fd, &num, sizeof(num));

        if (num > 0)
        {
            strcpy(buffer, "Positive.");
        }
        else if (num < 0)
        {
            strcpy(buffer, "Negative.");
        }
        else
        {
            strcpy(buffer, "zero");
        }
        write(client_fd, buffer, sizeof(buffer));
        close(client_fd);
    }
    close(server_fd);
    printf("Client disconnected\n");
}