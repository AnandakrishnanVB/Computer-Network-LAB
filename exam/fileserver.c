#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024
int main()
{
    int serverfd, clientfd;
    char filename[100];
    socklen_t len;
    char buffer[SIZE];
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(serverfd, 5);
    printf("Tcp server up...\n");
    while (1)
    {
        len = sizeof(client_addr);
        clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &len);
        if (fork() == 0)
        {
            close(serverfd);
            read(clientfd, filename, sizeof(filename));
            FILE *fp = fopen(filename, "r");
            sprintf(buffer, "server PID:%d\n\n", getpid());
            if (fp == NULL)
            {
                strcpy(buffer, "Requested file doesn't exist.\n");
                write(clientfd, buffer, sizeof(buffer));
            }
            else
            {
                while (fgets(buffer, SIZE, fp) != NULL)
                {
                    // fgets(buffer, size, file_pointer);
                    write(clientfd, buffer, sizeof(buffer));
                }
                fclose(fp);
            }
            close(clientfd);
            exit(0); // Really needed or the CPU get mad.
        }
    }
    close(clientfd);
}