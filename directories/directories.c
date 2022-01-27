/*
    PROGRAM TO LIST ALL FILES AND DIRECTORIES RECURSIVELY
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define MAX_NAME_LENGTH 255

void list_dirs_and_contents();

int main()
{   
    char source[MAX_NAME_LENGTH];

    printf("Input Directory: ");
    fgets(source, MAX_NAME_LENGTH, stdin);
    source[strlen(source) - 1 ] = 0;

    list_dirs_and_contents(source);
    
    return 0;
}

/*  List directories and files */
void list_dirs_and_contents(char directory[]){
    DIR *dp;
    struct dirent *entity;
    char subdir[1024];

    dp = opendir(directory);
    if (dp == NULL) {
        printf("Error occured during the opening.");
    } else {
        while ( (entity=readdir(dp)) )
        {    
            if ( strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0 ){
                if (entity->d_type == DT_DIR) {
                    printf("\nDirectory: %s\n", entity->d_name);
                    sprintf(subdir, "%s/%s", directory, entity->d_name);
                    list_dirs_and_contents(subdir);
                } else {
                    printf("File: %s\n", entity->d_name);
                }
            }
        }
    }
}