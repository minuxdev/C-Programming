/*
    PROGRAM TO WRITE INTO A FILE
*/

#include <stdio.h>
#include <string.h>

void write_file(char text[]);
int main()
{
    char text[255];
    write_file(text);
    return 0;
}

void write_file(char text[])
{
    FILE *fp;

    printf("Type in your text here! \n");
    scanf("%[^-f]", text);
    getchar();

    printf("\nYour text: %s", text);

    fp = fopen("mytext.txt", "w");
    if ( fp == NULL){
        printf("Error opening the file.");
    } else {
        fputs(text, fp);
        printf("your text was saved successfully...");
        }
}