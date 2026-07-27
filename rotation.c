#include<stdio.h>
#include "image.h"

//As it is a 64x64 matrix, n=64
int n=64;
int rotated[64][64];
int pixels[64][64];


void rotate90(){
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        rotated[n-j][i]=pixels[i][j];
    }
}
}

void rotate180(){
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        rotated[n-i][n-j]=pixels[i][j];
    }
}
}

void rotate270(){
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        rotated[j][n-i]=pixels[i][j];
    }
}
}


int main(){
readImage("lion_p2.pgm",pixels);
//FEATURE #2

int angle;
printf("Enter the angle by which you want to rotate the image (only multiples of 90°):\n");
scanf("%d",&angle);

//angle normalisation to ensure that the angles are only 90,180 or 270. Basically it brings it to the fundamental multiple of 90 deg. 
//In other words, this is to ensure, for eg, 450deg is converted to 90deg because both of them are the same
angle%=360;
if(angle<0){
    angle+=360;
}

FILE *fp2=fopen("feature2.pgm","w");
if(fp2==NULL) printf("Error in opening the file!\n");
else printf("Opened feature2.pgm successfully!\n");
fprintf(fp2,"P2\n64 64\n255\n");

switch(angle){
    case 90:
    rotate90();
    break;

    case 180:
    rotate180();
    break;

    case 270:
    rotate270();
    break;

    case 0:
    for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        rotated[i][j]=pixels[i][j];
    }
    }
    break;

    default:
    printf("Not a multiple of 90°\n");
    fclose(fp2);
    return 0;
    break;
}

for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        fprintf(fp2,"%d ",rotated[i][j]);
    }
    fprintf(fp2,"\n");
}

fclose(fp2);
system("magick feature2.pgm feature2_preview.png");
printf("Preview for feature 2 successfully created.\n");
}