#include <stdio.h>
#include <ctype.h>

void upper(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("Upper is %s", str);
}

int main()
{
    char str[100];
    printf("Enter a string:");
    scanf("%s", str);
    upper(str);
}