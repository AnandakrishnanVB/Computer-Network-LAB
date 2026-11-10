#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{
    char buffer[SIZE];
    char result[SIZE];

    printf("Enter the string:");
    scanf("%s", buffer);
    int len = strlen(buffer);
    buffer[len] = '\0';

    for (int i = 0; buffer[i]; i++)
    {
        result[i] = buffer[len - i - 1];
    }
    // 2nd way
    //  int i = len - 1;
    //  int j = 0;
    //  while (buffer[i])
    //  {
    //      result[j++] = buffer[i--];
    //  }
    printf("%s", result);
}