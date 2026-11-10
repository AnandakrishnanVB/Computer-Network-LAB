#include <stdio.h>

#define SIZE 100

int main()
{
    char buffer[SIZE];
    char result[SIZE];

    printf("Enter the string:");
    scanf("%s", buffer);
    int len = strlen(buffer);

    for (int i = len; i >= 0; i--)
    {
        printf("%s", buffer[i]);
    }
}