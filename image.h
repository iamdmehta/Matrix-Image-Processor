#ifndef IMAGE_H
#define IMAGE_H

#define SIZE 64

void readImage(const char *filename, int pixels[SIZE][SIZE]);
void writeImage(const char *filename, int pixels[SIZE][SIZE], int maxval);

void brightness(int pixels[SIZE][SIZE], int brightness_value);
void rotation(int pixels[SIZE][SIZE], int angle);
void blur(int pixels[SIZE][SIZE]);
void edgeDetection(int pixels[SIZE][SIZE]);

#endif