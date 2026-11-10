#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[100];
    printf("Enter the string:");
    scanf("%s", buffer);
    int len = strlen(buffer); // Hello\0
    buffer[len] = '\0';
    int count = 0;
    for (int i = 0; buffer[i]; i++)
    {
        count++;
    }
    printf("Number of charaters:%d", count);

    // Wait just use the strlen()😂
}