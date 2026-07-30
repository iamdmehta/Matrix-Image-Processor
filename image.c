#include <stdio.h>
#include "image.h"

void readImage(const char *filename, int pixels[SIZE][SIZE])
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening %s\n", filename);
        return;
    }

    char format[3];
    int width, height, maxval;

    fscanf(fp,"%2s",format);
    fscanf(fp,"%d %d",&width,&height);
    fscanf(fp,"%d",&maxval);

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            fscanf(fp,"%d",&pixels[i][j]);
        }
    }

    fclose(fp);

    printf("Image loaded successfully.\n");
}

void writeImage(const char *filename, int pixels[SIZE][SIZE], int maxval)
{
    FILE *fp = fopen(filename,"w");

    if(fp == NULL)
    {
        printf("Error creating %s\n",filename);
        return;
    }

    fprintf(fp,"P2\n");
    fprintf(fp,"%d %d\n",SIZE,SIZE);
    fprintf(fp,"%d\n",maxval);

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            fprintf(fp,"%d ",pixels[i][j]);
        }
        fprintf(fp,"\n");
    }

    fclose(fp);

    printf("%s created successfully.\n",filename);
}