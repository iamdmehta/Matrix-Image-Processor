#include<stdio.h>
#include<stdlib.h>
#include "image.h"
#include <math.h>

int main(){
    int pixels[64][64];
    int edge[64][64]={0};

    readImage("lion_p2.pgm",pixels);
    FILE *fp1=fopen("feature4.pgm","w");
    if(fp1==NULL){
        printf("Error in opening the file!\n");
        return -1;
    }
    else{
        printf("feature4.pgm file opened successfully!\n");
    }


    int Gx[3][3]={-1,0,1,-2,0,2,-1,0,1};
    int Gy[3][3]={-1,-2,-1,0,0,0,1,2,1};

    //preserves the borders
    for (int j = 0; j < 64; j++)
    {
    edge[0][j] = pixels[0][j]; //top row
    edge[63][j] = pixels[63][j]; //bottom column
    }

    for (int i = 0; i < 64; i++)
    {
    edge[i][0] = pixels[i][0]; //left most column
    edge[i][63] = pixels[i][63]; //right most column
    }

    double sum_Gx=0,sum_Gy=0;
    for(int i=1;i<63;i++){
        for(int j=1;j<63;j++){
            sum_Gx=0;sum_Gy=0;
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    sum_Gx+=(pixels[i+di][j+dj] * Gx[di+1][dj+1]);
                    sum_Gy+=(pixels[i+di][j+dj] * Gy[di+1][dj+1]);
                }
            }
            edge[i][j]=(int)sqrt(sum_Gx*sum_Gx + sum_Gy*sum_Gy);
        }
    }

fprintf(fp1,"P2\n64 64\n820\n");
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
    fprintf(fp1,"%d ",edge[i][j]);
    }
    fprintf(fp1,"\n");
}

fclose(fp1);

system("magick feature4.pgm feature4.png");
printf("Feature 4 preview is ready to view.\n");

}