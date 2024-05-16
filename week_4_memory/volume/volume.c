// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[]) // enter in your input, output, factor
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE];          // create an array as buffer (header) to hold information
    fread(header, 1, HEADER_SIZE, input); // read header from input file and store in buffer
    fwrite(header, 1, HEADER_SIZE, output); // write header from buffer into output file

    // Read samples from input file and write updated data to output file
    int16_t sample; // create a buffer variable

    while (fread(&sample, sizeof(int16_t), 1, input) !=
           0) // loop through doc- aka while fread != 0 and read in sample to buffer
    {
        sample = sample * factor;                    // modify buffer with factor
        fwrite(&sample, sizeof(int16_t), 1, output); // write buffer to output file
    }

    // Close files
    fclose(input);
    fclose(output);
}
