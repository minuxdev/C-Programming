#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define MAX_NAME_LENGTH 255

void open_dir();

int main()
{   
    
    char source[MAX_NAME_LENGTH], dest[MAX_NAME_LENGTH];


    printf("Input Directory: ");
    scanf("%[^\n]", source);

    printf("To: ");
    scanf("%[^\n]", dest);

    open_dir(source);

    
    return 0;
}

/*  List directories and files */
void open_dir(char directory[]){
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
                    printf("directory: %s\n", entity->d_name);
                    sprintf(subdir, "%s/%s", directory, entity->d_name);
                    open_dir(subdir);
                } else {
                    printf("File: %s\n", entity->d_name);
                }
            }
        }
    }
}