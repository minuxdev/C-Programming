/*
    A PROGRAM TO READ AND WRITE BYTES
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *rp, *wp;
    char file[255], new_file[255];
    char buffer[4096];
    int r, w, transfered_byte = 0;

    // get inputs
    printf("From: ");
    fgets(file, 255, stdin);
    file[strlen(file) -1] = 0;

    printf("To: ");
    fgets(new_file, 255, stdin);
    new_file[strlen(new_file) -1] = 0;

    // METHOD 1 [THE RECOMMENDED WAY]
    // 1 - Open stream files
    // rp - existing file
    rp = fopen(file, "rb");

    // wp - file to write into
    wp = fopen(new_file, "wb");

    // Checking the status return
    if (rp !=NULL){
        if (wp != NULL){
            printf("Copying: %s\n", file);
            while (r > 0){
                /*
                    buffer > array that hold the bytes
                    sizeof(buffer) > size to be allocated in memory
                    1 - number of files to be read or writen
                    rp/wp - readed and write streams
                */
               // storing readed bytes into buffer array
                r = fread(buffer, sizeof(buffer), 1, rp);
                // writing bytes from buffer to wp
                fwrite(buffer, sizeof(buffer), 1, wp);
                transfered_byte += sizeof(buffer);
                
                printf("Transfered bytes: %d\n", transfered_byte);
                // system("clear");
            }
            printf("File created successfully!\n");
        } else {
            printf("Error occcured writing into a file!");
            exit(2);
        }
    } else {
        printf("Error coccured reading file!");
        exit(1);
    }


    // METHOD TWO [NOT RECOMMENDED WAY DUE THE INCOMPATIBILITIES WITH NON POSIX SYSTEMS]
    /*
    <fcntl.h> header file must be included!

    rp = open(file, O_RDONLY); >>> open in read mode only
    wr = open(new_file, O_WDONLY | O_CREATE); >>> open in write mode [create if it doesnt exist]
    
    * CHECK THE STATUS OF rp and wp *
    do
    {
        r = read(rp, sizeof(buffer), buffer);
        fwrite(wp, sizeof(buffer), buffer);

    } while (r > 0);
    */
    close(rp);
    close(wp);

    return 0;
}