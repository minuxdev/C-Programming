/*
A PROGRAM TO TRANSFER FILES
*/

#include <stdio.h>
#include <string.h>

// defining the max length of any array
#define MAX_LEN 255

// prototyping the functions
void transfer_file(char src[], char dst[]);
char* str_concat(char src[MAX_LEN], char dst[MAX_LEN]);
char* get_file_name(char src[MAX_LEN]);

// main program
int main(){
    char src[MAX_LEN], dst[MAX_LEN];

    // getting the source file path and destity directory paths
    printf("From: ");
    fgets(src, MAX_LEN, stdin);
    src[strlen(src) - 1] = 0;

    printf("To: ");
    fgets(dst, MAX_LEN, stdin);
    dst[strlen(dst) -1] = 0;

    // creating the full path of new file
    char *new_path = str_concat(src, dst);

    // transfering the file
    transfer_file(src, new_path);

    return 0;
}

// reading and writing files
void transfer_file(char src_file[], char dst_file[]){
    FILE *sf, *df;
    int chr;

    sf = fopen(src_file, "r");
    if (sf == NULL){
        printf("Error reading file!");
    } else {
        df = fopen(dst_file, "w");
        if (df != NULL){
            while ( (chr = fgetc(sf)) != EOF) {
                fputc(chr, df);
            }
            fclose(sf);
            fclose(df);
        } else {
            printf("An error occured during the write!");
            fclose(sf);
        }
    }
}


// splitting sorce path to get the file name
char* get_file_name(char src[MAX_LEN])
{
    char *peace = strtok(src, "/");
    char * name;
    while( peace != NULL){
        name = peace;
        peace = strtok(NULL, "/");
    }
    return name;
}

// constructing the new file full path 
char* str_concat(char src[MAX_LEN], char dst[MAX_LEN])
{  
    char *file_name = get_file_name(src);
    strcat(dst, "/");
    strncat(dst, file_name, 50);
    puts(dst);
    return dst;
}
