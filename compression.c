#include<stdio.h>
#include<stdlib.h>
#include "image.h"

int main(){
    int pixels[64][64];

    readImage("chatgpt_logo_p2.pgm",pixels);


    FILE *fp1=fopen("chatgpt_logo_compressed.txt","w");
    if(fp1==NULL){
        printf("Error in opening the file!\n");
        return -1;
    }
    else{
        printf("chatgpt_logo_compressed.txt file opened successfully!\n");
    }
    fprintf(fp1,"P2RLE\n64 64\n255\n");


    int currentValue,count=0;

    currentValue=pixels[0][0];
    count=1;
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            if(i==0 && j==0) continue;

            if(currentValue==pixels[i][j]) count++;
            else{
                fprintf(fp1,"%d %d\n",currentValue,count);
                currentValue=pixels[i][j];
                count=1;
            }
        }
    }
    fprintf(fp1,"%d %d\n",currentValue,count);

printf("chatgpt_logo_p2.pgm file has been compressed and the compressed file now is named chatgpt_logo_compressed.txt\n");
}