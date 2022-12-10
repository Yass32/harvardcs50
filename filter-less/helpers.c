#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Loops through rows
    {
        for (int j = 0; j < width; j++) //Loops through column
        {
            double Avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0; //Find the avg color value of pixel and store in x
            int x = round(Avg);
            image[i][j].rgbtBlue = x; //Applies x to each colour to create grayscale
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtRed = x;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //Loops through rows
    {
        for (int j = 0; j < width; j++) //Loops through column
        {
            // Apply formula to pixel
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaBlue > 255) // Loop to make sure result of formula doesnt exceed 255
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue; //Applies new colour to final image
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++) //Loops through rows
    {
        int CurPos = 0;
        for (int j = width - 1; j >= 0; j--, CurPos++) //Loops through column
        {
            temp[i][CurPos] = image[i][j]; //Assign opposite/reflected pixels to a buffer
        }
    }
    for (int i = 0; i < height; i++) //Loops through rows
    {
        for (int j = 0; j < width; j++) //Loops through column
        {
            image[i][j] = temp[i][j]; //Assign buffer pixels to final image
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
