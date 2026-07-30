#include "image.h"

void brightness(int pixels[SIZE][SIZE], int brightness_value)
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            pixels[i][j] += brightness_value;

            if(pixels[i][j] > 255)
                pixels[i][j] = 255;

            else if(pixels[i][j] < 0)
                pixels[i][j] = 0;
        }
    }
}