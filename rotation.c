#include <stdio.h>
#include "image.h"

void rotate90(int pixels[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            temp[j][SIZE-1-i] = pixels[i][j];
        }
    }

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            pixels[i][j] = temp[i][j];
        }
    }
}

void rotate180(int pixels[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            temp[SIZE-1-i][SIZE-1-j] = pixels[i][j];
        }
    }

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            pixels[i][j] = temp[i][j];
        }
    }
}

void rotate270(int pixels[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            temp[SIZE-1-j][i] = pixels[i][j];
        }
    }

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            pixels[i][j] = temp[i][j];
        }
    }
}

void rotation(int pixels[SIZE][SIZE], int angle)
{
    switch(angle)
    {
        case 90:
            rotate90(pixels);
            break;

        case 180:
            rotate180(pixels);
            break;

        case 270:
            rotate270(pixels);
            break;

        case 0:
            break;

        default:
            printf("Not a multiple of 90°\n");
    }
}