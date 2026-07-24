#include <stdio.h>
#include <stdlib.h>

int pixels[64][64];
int rotated[64][64];

//As it is a 64x64 matrix, n=64
int n=64;

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
FILE *fp;

fp=fopen("lion_p2.pgm","r");
if(fp==NULL) printf("Error in opening the file.\n");
else printf("File opened successfully!\n");

//to skip the first 3 lines of .pgm file because it just info about the contents of the file and not the contents of the file itself.
char format[3];
int width, height, maxval;

fscanf(fp, "%2s", format);
fscanf(fp, "%d %d", &width, &height);
fscanf(fp, "%d", &maxval);

// for loop to take the intensity of each pixel into a 64x64 matrix 
for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
        fscanf(fp,"%d",&pixels[i][j]);
    } 
}


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
fclose(fp);
system("magick feature1.pgm feature1_preview.png");
printf("Preview for feature 1 successfully created.\n");

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