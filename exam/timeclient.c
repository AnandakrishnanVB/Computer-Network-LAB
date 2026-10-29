#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024
int main()
{
    int sockfd;
    char buffer[SIZE] = "TIME";
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET."127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT)

    
}