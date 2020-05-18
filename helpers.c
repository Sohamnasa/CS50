#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float x = round (((float)image[i][j].rgbtRed + (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen )/3);
            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtBlue = x;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a = round (((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue)));
            int b = round (((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue)));
            int c = round (((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue)));

            if (a > 255)
            {
                a = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
            if (c > 255)
            {
                c = 255;
            }

            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = b;
            image[i][j].rgbtBlue = c;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;
            
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j -1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
    return;
}

int equation(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB)
{
    float counter = 0;
    int sum = 0;
    for (int k = i - 1; k < (i + 2); k++)
    {
        for (int l = j - 1; l < (j + 2); l++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {

            }
            else
            {
                if (RGB == 0)
                {
                    sum += image[k][l].rgbtRed;
                }
                else if (RGB == 1)
                {
                    sum += image[k][l].rgbtBlue;
                }
                else
                {
                    sum += image[k][l].rgbtGreen;
                }
                counter++;
            }
        }
    }
    return round(sum / counter);

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = equation(i, j, height, width, copy, 0);
            image[i][j].rgbtBlue = equation(i, j, height, width, copy, 1);
            image[i][j].rgbtGreen = equation(i, j, height, width, copy, 2);
        }
    }
    return;
}
