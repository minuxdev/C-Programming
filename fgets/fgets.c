#include <stdio.h>
#include <string.h>


int main(){
    char word[255];
    int i;

    printf("word: ");
    fgets(word, 255, stdin);
    word[strlen(word) - 1] = 0; 
    
    // The up line is equivalent to getchar() function 
    // witch can be used with scanf to remove the last char from the buffer

    for (i = 0; i <= strlen(word); i++){
        printf("[ %d ]", word[i]);
    }

    return 0;
}