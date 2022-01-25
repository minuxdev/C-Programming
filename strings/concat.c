#include <stdio.h>
#include <string.h>

#define MAX_LEN 255

char str_concat(char str1[MAX_LEN], char str2[MAX_LEN]);

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Str1: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strlen(str1) -1 ] = 0;
    printf("Str2: \n");
    fgets(str2, MAX_LEN, stdin);
    str2[strlen(str2) -1 ] = 0;

    str_concat(str1, str2);
    return 0;
}

char str_concat(char str1[MAX_LEN], char str2[MAX_LEN])
{
    strcat(str1, "/");
    strncat(str1, str2, 30);
    puts(str1);
    return str1;
}