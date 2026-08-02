#include <stdio.h>
#include "image.h"

void blur(int pixels[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            int sum = 0;
            int count = 0;

            for(int di=-1;di<=1;di++)
            {
                for(int dj=-1;dj<=1;dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if(ni>=0 && ni<SIZE && nj>=0 && nj<SIZE)
                    {
                        sum += pixels[ni][nj];
                        count++;
                    }
                }
            }

            temp[i][j] = sum / count;
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