#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_LEN 255
#define MODE 0775


void copy_content(char src[MAX_LEN], char dst[MAX_LEN]);
void make_dir(char dst[]);
void read_write(char file_name[], char new_file[]);

int main(void)
{
    char src[MAX_LEN], dst[MAX_LEN];

    printf("From: \n");
    fgets(src, MAX_LEN, stdin);
    src[strlen(src) -1] = 0;

    printf("To: \n");
    fgets(dst, MAX_LEN, stdin);
    dst[strlen(dst) -1] = 0;

    copy_content(src, dst);
    return 0;
}


// 1 - List Directory contents
void copy_content(char src[MAX_LEN], char dst[MAX_LEN])
{
    DIR *sp, *dp;
    struct dirent *entity;
    char name[100], subdir[100];


    sp = opendir(src);
    if (sp == NULL){
        printf("Error opening directory.");
        exit(1);
    } else {
        dp = opendir(dst);
        if (dp == NULL){
            printf("Error opening destiny path.");
            exit(1);
        } else {
            while ( (entity = readdir(sp)) ){
                if ( strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0){
                    if (entity->d_type == DT_DIR){
                        printf("\nDirectory: %s\n", entity->d_name);
                        sprintf(name, "%s/%s", dst, entity->d_name);
                        make_dir(name);
                        printf("New Dest: %s\n", name);
                        sprintf(subdir, "%s/%s", src, entity->d_name);
                        printf("Subdir: %s\n", subdir);
                        copy_content(subdir, name);
                    } else {
                        sprintf(name, "%s/%s", dst, entity->d_name);
                        sprintf(subdir, "%s/%s", src, entity->d_name);
                        printf("Source File: %s\n", subdir);
                        printf("Dest File: %s\n", name);
                        read_write(subdir, name);
                    }
                }
                // puts(entity->d_name);
            }
        }
    }
}

void make_dir(char dst[])
{   
    int stat = mkdir(dst, MODE);
    if (stat == 0){
        printf("\n**** Directory created successfully! ****\n");
    } else {
        printf("Operation failed!");
    }
}


// Read and Write content into new file
void read_write(char file_name[], char new_file[])
{
    FILE *sp, *dp;
    char ch;

    printf("File to read: %s\n\n", file_name);
    printf("File to write on: %s\n\n", new_file);

    sp = fopen(file_name, "rb");
    if ( sp == NULL ){
        printf("Error opening the file!\n");
        exit(1);
    } else {
        dp = fopen(new_file, "wb");
        if ( dp == NULL ) {
            printf("Error writing into a file...\n");
            exit(1);
        } else {
            while ( (ch = fgetc(sp)) != EOF ){
                fputc(ch, dp);
            }
            fclose(sp);
            fclose(dp);
            printf("File transfered...");
        }
    }
}


// /Users/minux/Documents/c-lab/source
// /Users/minux/Documents/c-lab/dest
