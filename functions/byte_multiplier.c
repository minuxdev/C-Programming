/*
    PROGRAM TO CONVERT BYTES (BASE 10)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void byte_multiplier(long int bytes, char* str);
void clear_buffer();

int main()
{
    char str[255];
    long int bytes;

    printf("How many Bytes: ");
    scanf("%ld", &bytes);
    clear_buffer();

    byte_multiplier(bytes, str);
    puts(str);

    return 0;
}

// CONVERT FROM BYTE TO [KB, MB, GB OR TB]
void byte_multiplier(long int bytes, char* str)
{
    double size;
    char text[40];
    float base = 1000;
    
    if (bytes <= 1000){
        sprintf(text, "Bytesf Bdes", bytes);
    } else if (bytes <= pow(1000, 2)) {
        size = (double) bytes / 1000;
        sprintf(text, "%.2lf Kb", size);
    } else if (bytes <= pow(1000, 3)) {
        size = (double) bytes / pow(1000, 2);
        sprintf(text, "%.2lf Mb", size);
    } else if (bytes <= pow(1000, 4)) {
        size = (double) bytes / pow(1000, 3);
        sprintf(text, "%.3lf Gb", size);
    } else {
        size = (double) bytes / pow(1000, 4);
        sprintf(text, "%.3lf Tb", size);
    }

    strcpy(str, text);
}

// CLEAR THE BUFFER AFTER USER INPUT
void clear_buffer(){
    char ch;
    while ( (ch = getchar()) != '\n' && ch != EOF );
}