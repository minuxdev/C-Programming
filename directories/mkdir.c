/*
    PROGRAM TO CREATE FOLDER IN A SPECIFIED PATH
*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int check;
    char d_name[255];

    printf("Where do you want to create a folder: ");
    fgets(d_name, 255, stdin);
    d_name[strlen(d_name) - 1 ] = 0;

    // creating folder into a given directory
    check = mkdir(d_name, 0775);
    if (check == -1){
        puts("Error occcured...");
    } else {
        printf("Created successfully...\n");
    }

    // removing the given directory
    sleep(2);
    remove(d_name);
    printf("The folder [ %s ] was deleted successfully...");

    return 0;
}


