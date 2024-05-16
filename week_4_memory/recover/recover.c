#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // enter in memory card file name as your command line argument. Error 1 if not entered
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    // Open files for reading. if you cannot open the file for reading error 1
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // create buffer, JPEG counter variable, Output file name, file open detection
    uint8_t jpeg_block[BUFFER_SIZE];
    int jpeg_counter = 0;
    char outputfilename[8];
    bool isFileOpen = false;
    sprintf(outputfilename, "%03i.jpg", jpeg_counter);
    FILE *outputfile = NULL;

    // read 512 bytes into buffer using fread until you run out of memory
    while (fread(jpeg_block, sizeof(uint8_t), BUFFER_SIZE, input) == BUFFER_SIZE)
    {
        // if start of new jpeg detected
        if (jpeg_block[0] == 0xff && jpeg_block[1] == 0xd8 && jpeg_block[2] == 0xff &&
            (jpeg_block[3] & 0xf0) == 0xe0)
        {
            if (isFileOpen == false)
            {
                sprintf(outputfilename, "%03i.jpg", jpeg_counter);
                outputfile = fopen(outputfilename, "w");
                if (outputfile == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }
                fwrite(jpeg_block, sizeof(uint8_t), BUFFER_SIZE, outputfile);
                isFileOpen = true;
                jpeg_counter++;
            }
            else
            {
                fclose(outputfile); // fclose prior jpeg file
                sprintf(outputfilename, "%03i.jpg", jpeg_counter);
                outputfile = fopen(outputfilename, "w");
                if (outputfile == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }
                fwrite(jpeg_block, sizeof(uint8_t), BUFFER_SIZE, outputfile);
                isFileOpen = true;
                jpeg_counter++;
            }
        }
        else // if not start of a new jpeg
        {
            if (isFileOpen == true) // if already writing to a file, keep writing
            {
                fwrite(jpeg_block, sizeof(uint8_t), BUFFER_SIZE, outputfile);
            }
        }
    }
    // at the end of the memory card close all open files
    fclose(input);
    fclose(outputfile);
}
