#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "image.h"

void edgeDetection(int pixels[SIZE][SIZE])
{
    int edge[SIZE][SIZE] = {0};

    int Gx[3][3] =
    {
        {-1,0,1},
        {-2,0,2},
        {-1,0,1}
    };

    int Gy[3][3] =
    {
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}
    };

    double sum_Gx, sum_Gy;

    for(int i=1;i<SIZE-1;i++)
    {
        for(int j=1;j<SIZE-1;j++)
        {
            sum_Gx = 0;
            sum_Gy = 0;

            for(int di=-1;di<=1;di++)
            {
                for(int dj=-1;dj<=1;dj++)
                {
                    sum_Gx += pixels[i+di][j+dj] * Gx[di+1][dj+1];
                    sum_Gy += pixels[i+di][j+dj] * Gy[di+1][dj+1];
                }
            }

            edge[i][j] = (int)sqrt(sum_Gx*sum_Gx + sum_Gy*sum_Gy);
        }
    }

    FILE *fp = fopen("feature4.pgm","w");

    if(fp == NULL)
    {
        printf("Error creating feature4.pgm\n");
        return;
    }

    fprintf(fp,"P2\n");
    fprintf(fp,"%d %d\n",SIZE,SIZE);
    fprintf(fp,"820\n");

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            fprintf(fp,"%d ",edge[i][j]);
        }

        fprintf(fp,"\n");
    }

    fclose(fp);
}