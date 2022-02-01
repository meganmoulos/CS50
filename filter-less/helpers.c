#include <math.h>
#include <stdio.h>

#include "helpers.h"

RGBTRIPLE average(int height, int width, RGBTRIPLE image[height][width], int row, int col);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For each pixel, average the RGB values, round to the nearest integer,
    // Loop through image, iterating through rows and columns to set each pixel R, G, and B values to gray value found above

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redValue = image[i][j].rgbtRed;
            int blueValue = image[i][j].rgbtBlue;
            int greenValue = image[i][j].rgbtGreen;
            int grayValue = round(((float)redValue + (float) blueValue + (float) greenValue) / 3);
            image[i][j].rgbtRed = grayValue;
            image[i][j].rgbtBlue = grayValue;
            image[i][j].rgbtGreen = grayValue;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel, applying the sepia formula to find the new color.
    // Set R, G, B values to the new sepia color values
    // Round to nearest integer and cap values at 255
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            float sepiaRed = (.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue);
            float sepiaGreen = (.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue);
            float sepiaBlue = (.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue);
            int newRed = round(sepiaRed);
            int newBlue = round(sepiaBlue);
            int newGreen = round(sepiaGreen);
            if (newRed > 255)
            {
                newRed = 255;
                image[i][j].rgbtRed = newRed;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }
            if (newBlue > 255)
            {
                newBlue = 255;
                image[i][j].rgbtBlue = newBlue;
            }
            else
            {
                image[i][j].rgbtBlue = newBlue;
            }
            if (newGreen > 255)
            {
                newGreen = 255;
                image[i][j].rgbtGreen = newGreen;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Each individual pixel in the row switches places horizontally
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy the image, read pixels' colors from copy
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    // Write the new pixel colors into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = average(height, width, copy, i, j);
        }
    }
    return;
}

// Function for finding the average of nearby pixels
RGBTRIPLE average(int height, int width, RGBTRIPLE image[height][width], int row, int col)
{
    int counter = 0;
    int redTotal = 0;
    int greenTotal = 0;
    int blueTotal = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i < 0 || i >= height)
            {
                continue;
            }
            if (j < 0 || j >= width)
            {
                continue;
            }
            counter++;
            redTotal = redTotal + image[i][j].rgbtRed;
            greenTotal = greenTotal + image[i][j].rgbtGreen;
            blueTotal = blueTotal + image[i][j].rgbtBlue;
        }
    }
    int redAverage = round((float) redTotal / counter);
    int greenAverage = round((float) greenTotal / counter);
    int blueAverage = round((float) blueTotal / counter);

    RGBTRIPLE average;
    average.rgbtRed = redAverage;
    average.rgbtGreen = greenAverage;
    average.rgbtBlue = blueAverage;
    return average;
}