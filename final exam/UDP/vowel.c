#include <stdio.h>
#include <ctype.h>

int main()
{
    int count = 0;
    char buffer[100];
    printf("Enter the string:");
    fgets(buffer, sizeof(buffer), stdin);
    for (int i = 0; buffer[i]; i++)
    {
        buffer[i] = tolower(buffer[i]);
        if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u')
        {
            count++;
        }
    }
    printf("Number of vowels : %d", count);
}