#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000

int main()
{
    int server_fd, client_fd, num;
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1)
    {
        listen(server_fd, 6);
        printf("server up..\n");
        client_fd = accept(server_fd, NULL, NULL);

        read(client_fd, &num, sizeof(num));

        int fact = 1;
        for (int i = 1; i <= num; i++)
        {
            fact = fact * i;
            printf("%d ", i);
        }
        write(client_fd, &fact, sizeof(fact));
    }
    close(client_fd);
    close(server_fd);
}