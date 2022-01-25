#include <stdio.h>
#include <string.h>

#define MAX_LEN 255

char file_name(char str[MAX_LEN]);

int main(){
    char path[MAX_LEN];

    printf("Path: ");
    fgets(path, MAX_LEN, stdin);
    path[strlen(path) - 1] = 0;

    file_name(path);
    return 0;
}

char file_name(char str[MAX_LEN]){
    char *p = strtok(str, "/");
    char *p1 = p;
    puts(p1);
    while (p != NULL){
        puts(p);
        p1 = p;
        p = strtok(NULL, "/");
    }
    printf("Last Peace: %s", p1);
    return p1;
}