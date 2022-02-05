#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

extern int errno;

#define MAX_LEN 255
#define MODE 0775


void copy_content(char src[MAX_LEN], char dst[MAX_LEN]);
void make_dir(char dst[]);
void read_write(char file_name[], char new_file[]);
void get_src_name(char *src, char *src_n);
void create_parent_dir(char dst, char *src_dir, char src_n);

int main(void)
{
    char src[MAX_LEN], dst[MAX_LEN];

    printf("From: ");
    fgets(src, MAX_LEN, stdin);
    src[strlen(src) -1] = 0;

    printf("To: ");
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
    char src_n[100], src_dir[MAX_LEN];

    puts(src);


    sp = opendir(src);
    if (sp == NULL){
        perror("Message: ");
        exit(1);
    } else {
        dp = opendir(dst);
        if (dp == NULL){
            printf("Error opening destiny path.");
            perror("Error: ");
            exit(2);
        } else {
            get_src_name(src, src_n);
            sprintf(src_dir, "%s/%s", dst, src_n);
            make_dir(&src_dir);

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
                        
                        printf("SRC: %s\nSUBDIR: %s\n", src, subdir);

                        printf("Source File: %s\n", subdir);
                        printf("Dest File: %s\n", name);

                        read_write(subdir, name);
                    }
                }
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
        perror("Message: ");
    }
}


// Read and Write content into new file
void read_write(char file_name[], char new_file[])
{
    FILE *sp, *dp;
    char buffer[128];
    int byte = 1;

    memset(buffer, 0, sizeof(buffer));
    // printf("File to write on: %s\n\n", new_file);

    sp = fopen(file_name, "rb");
    if ( sp == NULL ){
        perror("Message: ");
        exit(1);
    } else {
        dp = fopen(new_file, "wb");
        if ( dp == NULL ) {
            perror("Message: ");
            exit(1);
        } else {
            printf("*** Reading bytes *** \n%d\n", byte);
            while ( byte > 0 ){
                byte = fread(buffer, sizeof(buffer), 1, sp);
                fwrite(buffer, sizeof(buffer), 1, dp);
            }
            fclose(sp);
            fclose(dp);
            printf("File transfered...\n");
        }
    }
}


void get_src_name(char *src, char *src_n)
{
    char *p1, *name;
    char local_src[MAX_LEN];

    strcpy(local_src, src);

    p1 = strtok(local_src, "/");
    while (p1 != NULL){
        name = p1;
        p1 = strtok(NULL, "/");
    }
    strcpy(src_n, name);
    puts(src_n);
}

void create_parent_dir(char dst, char *src_dir, char src_n)
{
    puts(dst);
    puts(src_dir);
    puts(src_n);

    // strcpy(src_dir, dst);
    // strcat(src_dir, "/");
    // strcat(src_dir, src_n);
}

// /Users/minux/Documents/c-lab/source
// /Users/minux/Documents/c-lab/dest
