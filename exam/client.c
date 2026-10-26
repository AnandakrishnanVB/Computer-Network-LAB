// 1. Create a socket using socket().
// 2. Configure the server's IPv4 address and port.
// 3. Connect to the server using connect().
// 4. Send and receive data using write() and read().
// 5. Close the socket using close().

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int client_socket;
    int n, fact;

    struct sockaddr_in server; // Stores the server IP and port.

    client_socket = socket(AF_INET, SOCK_STREAM, 0); // IPV4,TCP.

    server.sin_addr = AF_INET;                         // Uses IPV4.
    server.sin_port = htons(8080);                     // Port 8080.
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // It connects to the server running on the same computer.
    // inet_pton( Address_Family(AF_INET), "IP_String"(127.0.0.1), &Destination_Buffer(&server.sin_addr));

    // Now connect to the server.
    connect(client_socket, (struct sockaddr *)&server, sizeof(server));

    // Enter the number
    print("Enter the number:");
    scanf("%d", &n);

    write(client_socket, &n, sizeof(n));

    read(client_socket, &fact, sizeof(fact));

    printf("Factorial is %d", fact);
    close(client_socket);
}