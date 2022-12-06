#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Correct usage: ./recover IMAGE\n");
        return 1;
    }

    char* inputFile = argv[1];
    if(inputFile == NULL)
    {
        printf("Correct usage: ./recover IMAGE\n");
        return 1;
    }

    BYTE buffer[512];
    char* filename = malloc(8 * sizeof(char));
    FILE* outputPtr = NULL;
    int count_image;

    FILE* inputPtr = fopen(inputFile, "r");
    if(inputPtr == NULL)
    {
        printf("Unable to open file: %s\n", inputFile);
        return 1;
    }

    while(fread(buffer, sizeof(char), 512, inputPtr) == 512);
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", )
        }
    }


}
