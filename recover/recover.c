#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    string filename = argv[1];

    // Open the memory card
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error");
        return 1;
    }

    // Initialize variables
    BYTE buffer[512];
    int count = 0;
    char newFile[8];
    FILE *img = NULL;

    // Read 512 bytes into a buffer, repeat until end of memory card:
    while (fread(buffer, sizeof(BYTE), 512, f) == 512)
    {
        // Check for JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(newFile, "%03i.jpg", count);
            img = fopen(newFile, "w");
            count++;
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
        else if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }

    // Close any remaining files
    fclose(f);
    return 0;
}

