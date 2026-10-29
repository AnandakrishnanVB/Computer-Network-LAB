#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

int main()
{
    int sockfd;
    char buffer[SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("UDP time sserver is running");
    while (1)
    {
        len = sizeof(client_addr);
        recvfrom(sockfd, buffer, SIZE, 0, (struct sockaddr *)&client_addr, &len);
        time_t cur_time;
        time(&cur_time);
        strcpy(buffer, ctime(&cur_time));
        sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, len);
    }
    close(sockfd);
}