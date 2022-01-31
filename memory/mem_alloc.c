/*
    PROGRAM THAT ALLOCATE MEMORY DYNAMICALLY
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
    // 1 - MALLOC
    /*
        used to allocate memory (undefined initial value)
        it receive as argument an unsigned int (size_t n)
        will return NULL if something goes wrong or void pointer, therefore,
        you need to typecast to a proper type of data. 
        e.g. int = (int *) malloc(size_t 34);
    */

    // 2 - CALLOC
    /*
        same as malloc but it initialyze the with zero on each byte;
        first argument is an integer defining how many items will be stored
        and the second inform the size of each element;

        sizeof(type) - > will return the size (in bytes) needed to allocate the argument
    */

    system("clear");

    // 1 - MALLOC()
    int *p = (int *)malloc(5 * sizeof(int));
    *p = 2;

    char *sp = (char *) calloc(5, sizeof(char));
    *sp = 'M';

    printf("*** Allocated using malloc() ***\n");

    for (int i = 0; i < 5; i++){        
        if (i != 0){
            p[i] += p[i -1] * 2;
        }
        printf("%.2i - Adress: %p\t|  Value: %d\n", i + 1, &p[i], p[i]);
    }

    // 2 - CALLOC()
    printf("\n*** Allocated using calloc() ***\n");
    for (int i = 0; i < 5; i++) {
        if (i != 0){
            *(sp + i) = 'D';
        }
        printf("%.2d - Adress: %p -> Value: %c\n", i + 1, &sp[i], sp[i]);
    }
    // free() - > deallocate the memory pointed by ptr;
    // Note: It doesnt delete the content on the previeously allocated;
    // Its up to you clear it, e.g. using memset(ptr, 0, ptr size)).
    
    free(p);
    free(sp);

    return 0;
}

