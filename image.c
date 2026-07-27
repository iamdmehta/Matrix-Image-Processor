#include <stdio.h>
#include "image.h"

void readImage(const char *filename, int pixels[64][64])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error in opening the file.\n");
        return;
    }
    else
        printf("File opened successfully!\n");

    // to skip the first 3 lines of .pgm file because it just info about the contents of the file and not the contents of the file itself.
    char format[3];
    int width, height, maxval;

    fscanf(fp, "%2s", format);
    fscanf(fp, "%d %d", &width, &height);
    fscanf(fp, "%d", &maxval);

    // for loop to take the intensity of each pixel into a 64x64 matrix
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            fscanf(fp, "%d", &pixels[i][j]);
        }
    }
    fclose(fp);
}