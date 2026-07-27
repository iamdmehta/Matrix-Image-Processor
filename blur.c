#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main()
{
    int pixels[64][64];
    int blurred[64][64];
    readImage("lion_p2.pgm",pixels);
    int sum = 0;

    FILE *fp3 = fopen("feature3.pgm", "w");
    if (fp3 == NULL)
        printf("Error in creating feature3.pgm\n");
    else
        printf("feature3.pgm file created successfully!\n");

    fprintf(fp3, "P2\n64 64\n255\n");

    for (int j = 0; j < 64; j++)
    {
    blurred[0][j] = pixels[0][j];
    blurred[63][j] = pixels[63][j];
    }

    for (int i = 0; i < 64; i++)
    {
    blurred[i][0] = pixels[i][0];
    blurred[i][63] = pixels[i][63];
    }

    for (int i = 1; i < 63; i++)
    {
        for (int j = 1; j < 63; j++)
        {
            for (int di = -1; di <= 1; di++)
            { // di is basically delta i
                for (int dj = -1; dj <= 1; dj++)
                { // dj is delta j
                    sum += pixels[i + di][j + dj];
                }
            }
            blurred[i][j] = sum / 9;
            sum = 0;
        }
    }

    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            fprintf(fp3, "%d ", blurred[i][j]);
        }
    fprintf(fp3, "\n");
    }

    fclose(fp3);
    system("magick feature3.pgm feature3.png");
}