/*
    FUNCTION TO RETURN STRING
*/

#include <stdio.h>
#include <string.h>

char* return_string();
void copy_str(char* str);

int main()
{
    // 1 - THIS IS A READ ONLY STRING, CANNOT BE MODIFIED
    char *str1, str2[255];
    str1 = return_string();
    printf("String1: %s\n", str1);


    // 2 - THIS IS A COPIED STRING, CAN BE MODIFIED
    copy_str(str2);
    printf("\nString2: %s", str2);

    // modifying the string
    str2[5] = 'I';
    str2[20] = 'X';
    puts(str2);

    return 0;
}

// 1 - RETURNING POINTER 
/*
    NOTES: This is not the best way to do it just because the 
    string is allocated inside the function stack, meaning, 
    it only exist when the function is called and distroied 
    when it reach the end.
*/
char*  return_string()
{
    char *str = "Literal strings are stored into "
                "READ_ONLY_MEMORY, so they cannot be "
                " modified.";
    return str;
}

// 2 - COPY A STRING INTO A POINTER
/*
    THE RECOMENDED WAY
    This is the recomended method just because instead of using the literal 
    string itself we a copying it into an pointer and then pass to an array
    wherever we call the function. In this way we can access te string in 
    Read and Write mode.
*/
void copy_str(char *str)
{
    char text[] = "This is how you return a literal string that can be modified.";
    strcpy(str, text);
}
