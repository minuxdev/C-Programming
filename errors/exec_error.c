/*
    ERROR HENDLING 
*/


#include <errno.h>
#include <stdio.h>
#include <string.h>

extern int errno;

int main()
{
    FILE *fp;
    fp = fopen("c.tx", "r");
    if (fp == NULL){
        // printf("Error Message using strerror(): %s", strerror(errno));
        perror("Another way to show the error messsge: ");
    }

    int i;
    scanf("%s", &i);
    perror("Error: ");

    return 0;
}