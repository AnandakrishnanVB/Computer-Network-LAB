#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    char filename[20];
    char buffer[100];
    printf("Enter a file name:");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        strcpy(buffer, "File not found");
        printf("%s", buffer);
    }
    else
    {
        while (fgets(buffer, sizeof(buffer), fp) != NULL)
        {
            printf("%s", buffer);
        }
    }
    fclose(fp);
}