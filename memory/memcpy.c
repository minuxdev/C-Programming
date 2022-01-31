/*
    PROGRAM TO SHERE BYTES BETWEN MEMORY AREAS
*/

#include <stdio.h>
#include <string.h>

void memory_copy(char *src, char *dst);

int main()
{   
    char src[] = "Sorce string to destiny thru memcpy()";
    char dst[255];
    memory_copy(src, dst);

    return 0;
}

void memory_copy(char *src, char *dst)
{
    printf("*** Sorce bytes ***\n %s\n", src);
    

    memcpy(dst, src, strlen(src) * sizeof(char));
    printf("*** Dest bytes ***\n %s\n\n", dst);
}