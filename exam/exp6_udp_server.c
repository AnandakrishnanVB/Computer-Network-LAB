#include <stdio.h>
#include <string.h> //For the strcpy(),strcmp() functions
#include <ctype.h>  //For the tolower() function
#include <unistd.h> //For the close()
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

void translate(char *str)
{
    char temp[MAX]; // Used to store the string into a temp for modifying.
    char result[MAX];
    char *token;
    strcpy(temp, result);
    token = strtok(temp, ",.!?\n");
    // strtok() separates the sentence wherever it finds a space, comma, period, exclamation mark, question mark, or newline.
    while (token != NULL)
    {
        char word[50]; // A temp varibale used to hold the token.Not really required.
        strcpy(word, token);
        for (int i = 0; word[i]; i++)
        {
            word[i] = tolower(word[i]); // The tolower convert a charater into its lowercase.Not a full word.
        }
        if (strcmp(word, "tbh") == 0)
        {
            strcat(result, "to be honest");
        }
        else if (strcmp(word, "idc") == 0)
        {
            strcat(result, "i dont care");
        }
        else if (strcmp(word, "ig") == 0)
        {
            strcat(result, "I guess");
        }
        else if (strcmp(word, "tbf") == 0)
        {
            strcat(result, "to be fair");
        }
        else if (strcmp(word, "atm") == 0)
        {
            strcat(result, "at the moment");
        }
        else if (strcmp(word, "irl") == 0)
        {
            strcat(result, "in real life");
        }
        else if (strcmp(word, "lol") == 0)
        {
            strcat(result, "laughing out loud");
        }
        else if (strcmp(word, "asap") == 0)
        {
            strcat(result, "as soon as possible");
        }
        else if (strcmp(word, "omg") == 0)
        {
            strcat(result, "oh my God");
        }
        else if (strcmp(word, "ttyl") == 0)
        {
            strcat(result, "talk to you later");
        }
        else if (strcmp(word, "idk") == 0)
        {
            strcat(result, "I don't know");
        }
        else if (strcmp(word, "nvm") == 0)
        {
            strcat(result, "never mind");
        }
        else
        {
            strcat(result, token);
        }
        strcat(result, " ");
        token = strtok(NULL, " ,.!?\n");
    }
    strcpy(str, result);
}
int main()
{
    int server_socket;
    char buffer[MAX]; // To store the string.
    struct sockaddr_in server_addr, client_addr;
    socklen_t len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    // AF_INET -> IPV4.
    // SOCK_DGRAM = UDP.
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // We need to bind the socket with the IP and port informations like in the TCP.
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // To this point TCP and UDP has similar steps.

    printf("Udp server running...\n");

    // In the UDP we dont need to use the listen() and accept().
    recvfrom(server_socket, buffer, MAX - 1, 0, (struct sockaddr *)&client_addr, &len);
    // Also you cannot use NULL here because the sendto() need the address to send the data back.
    //(socket,buffer,length,flag,client address,size)
    printf("Received : %s\n", buffer);
    translate(buffer);

    sendto(server_socket, buffer, MAX + 1, 0, (struct sockaddr *)&client_addr, len);
    // In the sendto() we cannot use the NULL, beacuse it need the destination address.
    printf("Translated message sent.\n");
    close(server_socket);
}