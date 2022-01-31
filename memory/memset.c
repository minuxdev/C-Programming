/* 
    PROGRAM TO FILL MEMORY WITH CONSTANT BYTE
*/

#include <string.h>
#include <stdio.h>

void set_memory(char *char_arr, int *int_arr, int len);

int main(void)
{
    char leters[30] = "Minux Developer";
    int num[12] = {1,2,3,4,5,6,7,8,9,10,23,89};

    set_memory(leters, num, 12);
    return 0;
}

void set_memory(char *char_arr, int *int_arr, int len)
{
    // read content form arrays
    printf("*** Content from Char_Arr ***\n%s\n\n", char_arr);
    printf("*** Content from Int_Arr ***\n");

    for (int i = 0; i < len; i++){
        printf("%d ", int_arr[i]);
        // memset(int_arr[i], 1, sizeof(int));
    }
    
    // setting 'X' into char_array
    memset(char_arr, 'X', sizeof(char_arr[0]) * strlen(char_arr));
    memset(int_arr, 0, sizeof(int) * 12);
    printf("\n*** Values after MemSet() ***\nChar_array: %s\n", char_arr);

    for (int i = 0; i < len; i++){
        printf("%d ", int_arr[i]);
    }
}
