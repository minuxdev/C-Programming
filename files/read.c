/*
    PROGRAM TO READ FILE CONTENT
*/

#include <stdio.h>
#include <string.h>

void read_file(char file[]);

int main()
{
    char file[255];
    
    printf("Path to file: ");
    fgets(file, 255, stdin);
    file[strlen(file) - 1 ] = 0;

    read_file(file);
    return 0;
}


void read_file(char file[])
{
    FILE *fp;
    int ch;
    
    fp = fopen(file, "r");
    if ( fp == NULL){
        printf("Error occured opening the file...");
    } else {
        while ( (ch = fgetc(fp)) != EOF){
            printf("%c", ch);
        }
        fclose(fp);
    }
}