// 1. Create a socket using socket().
// 2. Configure the server address using IPv4 and a port number.
// 3. Bind the socket to the server address using bind().
// 4. Put the server socket into listening mode using listen().
// 5. Accept a client connection using accept().
// 6. Communicate with the client using read() and write().
// 7. Close the client socket using close().
// 8. Close the server socket using close().

#include <stdio.h>
#include <unistd.h> //The function 'close()' is used from this header file to close the socket after use.
#include <arpa/inet.h>

int main()
{
    int server_socket, client_socket;
    // server_socket -> socket used by the server.
    // client_socket -> socket used to communicate with the client.
    int n;
    //'n' is to store the numeber from the client.

    struct sockaddr_in server;
    // This stored the networks address and port details.
    socklent_t addr_len = sizeof(server); // this is used in the accept part.

    server_socket = socket(AF_INET, SOCK_STREAM, 0); // Created a TCP socket using TCP.
    // AF_INET = IPV4 address
    // SOCK_STREAM = TCP

    server.sin_family = AF_INET;         // set address family to IPV4
    server.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY = accept connection through any available internet.
    server.sin_port = htons(8080);       // The port number

    // Now assign the IP address and port to the server socket
    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    // syntax -> bind(socket_descriptor, (struct sockaddr *)&address, address_length);
    // The bind requires the address in 'struct sockaddr' type, that why we converting it.

    listen(server_socket, 5); // Put the socket into listeing mode.

    client_socket = accept(server_socket, (struct sockaddr *)&server, &addr_len);
    // accept() Waits for a client and returns a new socket for communicating with that client.

    // Now read the value.
    read(client_socket, &n, sizeof(n));
    // Factorial logic.
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *i;
    }
    // Write back to the client.
    write(client_socket, &fact, sizeof(fact));

    // Now close the socket.
    close(server_socket);
    close(client_socket);
}
