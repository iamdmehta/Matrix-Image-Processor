#include <stdio.h>
#include<stdlib.h>
#include "image.h"


int main(){
int pixels[64][64];
readImage("lion_p2.pgm",pixels);

//FEATURE #1
int brightness;
printf("Enter by how many notches you want to vary the brightness: \n");
scanf("%d",&brightness);

//for loop to vary the image brightness by the user inputted value
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        pixels[i][j]+=brightness;
        if(pixels[i][j]>255) pixels[i][j]=255;
        else if(pixels[i][j]<0) pixels[i][j]=0;
    } 
}

FILE *fp1=fopen("feature1.pgm","w");
if(fp1==NULL) printf("Error in opening the file.\n");
else printf("File created successfully!Ready to write to it.\n");
fprintf(fp1,"P2\n64 64\n255\n");
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        fprintf(fp1,"%d ",pixels[i][j]);
    } 
    fprintf(fp1,"\n");
}
printf("Writing to the file completed.\n");
fclose(fp1);

system("magick feature1.pgm feature1_preview.png");
printf("Preview for feature 1 successfully created.\n");

}