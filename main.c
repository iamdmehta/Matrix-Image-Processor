#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main()
{
    int pixels[SIZE][SIZE];
    int choice;

    do
    {
        printf("\n========== IMAGE PROCESSING ==========\n");
        printf("1. Brightness Adjustment\n");
        printf("2. Image Rotation\n");
        printf("3. Blur\n");
        printf("4. Edge Detection\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int brightness_value;

                readImage("lion_p2.pgm", pixels);

                printf("Enter by how many notches you want to vary the brightness:\n");
                scanf("%d", &brightness_value);

                brightness(pixels, brightness_value);

                writeImage("feature1.pgm", pixels, 255);
                system("magick feature1.pgm feature1_preview.png");

                printf("Preview for feature 1 successfully created.\n");
                break;
            }

            case 2:
            {
                int angle;

                readImage("lion_p2.pgm", pixels);

                printf("Enter the angle by which you want to rotate the image (only multiples of 90°): ");
                scanf("%d", &angle);

                angle %= 360;
                if(angle < 0)
                    angle += 360;

                rotation(pixels, angle);

                writeImage("feature2.pgm", pixels, 255);
                system("magick feature2.pgm feature2_preview.png");

                printf("Preview for feature 2 successfully created.\n");
                break;
            }

            case 3:
            {
                readImage("lion_p2.pgm", pixels);

                blur(pixels);

                writeImage("feature3.pgm", pixels, 255);
                system("magick feature3.pgm feature3_preview.png");

                printf("Preview for feature 3 successfully created.\n");
                break;
            }

            case 4:
            {
                readImage("lion_p2.pgm", pixels);

                edgeDetection(pixels);

                system("magick feature4.pgm feature4.png");

                printf("Preview for feature 4 successfully created.\n");
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Please enter a valid option!\n");
        }

    } while(choice != 0);

    return 0;
}