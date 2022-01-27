/*
    PROGRAM TO MANIPULATE STRINGS
*/

#include <stdio.h>
#include <string.h>


int main()
{
    char str1[40], str2[40], str3[255];
    int ret;
    char *sp;

    // receiving strings from user
    printf("String1: ");
    fgets(str1, 40, stdin);
    str1[strlen(str1) -1] = 0;

    printf("String2: ");
    fgets(str2, 40, stdin);
    str2[strlen(str2) -1] = 0;

    // Comparing strings;
    // Return 0 if [str1 == str2], < 0 if [strlen(str1) < strlen(str2)] and
    // > 0 if is opposite;
    ret = strcmp(str1, str2);

    printf("Return value is: %d\n", ret);

    if (ret == 0) {
        printf("\"%s\" and \"%s\" are the same.\n", str1, str2);
    } else if (ret > 0) {
        printf("\"%s\" Greater than \"%s\".\n", str1, str2);
    } else if (ret < 0) {
        printf("\"%s\" Lower than \"%s\".\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are not the same.\n", str1, str2);
    }


    // concatenate
    strcat(str3, str1);
    puts(str3);
    strcat(str3, str2);
    printf("Concatenated string: %s\n", str3);

    // finding string
    // Return the pointer to the first occorenc of a string
    // and (null) if theres not. NOTE: It is Case Sensitive
    sp = strstr(str1, "Dev");
    printf("Found string: %s", sp);

    return 0;
}