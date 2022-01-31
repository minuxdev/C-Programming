/*
    PROGRAM TO MOVE BYTES FROM ONE PLACE TO ANOTHER IN MEMORY
*/

#include <string.h>
#include <stdio.h>

void move_bytes(char *src, char *dst);

int main()
{
    char src[] = "I'll be copied to another space in memory";
    char dst[255];

    move_bytes(src, dst);
    return 0;
}

void move_bytes(char *src, char *dst)
{
    printf("*** Sorce bytes ***\n %s\n", src);

    memmove(dst, src, strlen(src) * sizeof(src));
    printf("*** Dest bytes ***\n %s\n\n", dst);
    printf("*** Sorce bytes ***\nGarbage: %s\n", src);
}