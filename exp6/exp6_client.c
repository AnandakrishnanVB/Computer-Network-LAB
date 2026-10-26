
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main()
{
    int sockfd;
    char message[MAX];
    char buffer[MAX];
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter sentence:\n");
    fgets(message, MAX, stdin);

    sendto(sockfd, message, strlen(message) + 1, 0,
           (struct sockaddr *)&server_addr, len);

    recvfrom(sockfd, buffer, MAX, 0,
             (struct sockaddr *)&server_addr, &len);

    printf("\nTranslated Sentence:\n%s\n", buffer);

    close(sockfd);
    return 0;
}
