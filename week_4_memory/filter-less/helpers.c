#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels (nested loop)
    for (int i = 0; i < height; i++) // loop rows
    {
        for (int j = 0; j < width; j++) // loop columns
        {
            // Take average of red, green, and blue
            double averagep =
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            averagep = round(averagep);

            // Update pixel values
            image[i][j].rgbtRed = averagep;
            image[i][j].rgbtGreen = averagep;
            image[i][j].rgbtBlue = averagep;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels (nested loop)
    for (int i = 0; i < height; i++) // loop rows
    {
        for (int j = 0; j < width; j++) // loop columns
        {
            // take original red and covert to sepiared
            double sepiared = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                              .189 * image[i][j].rgbtBlue;
            sepiared = round(sepiared);
            if (sepiared > 255)
            {
                sepiared = 255;
            }

            // take original green and covert to sepiagreen
            double sepiagreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                .168 * image[i][j].rgbtBlue;
            sepiagreen = round(sepiagreen);
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }

            // take original blue and conver to sepiablue
            double sepiablue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                               .131 * image[i][j].rgbtBlue;
            sepiablue = round(sepiablue);
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }
            // update pixels with sepia values
            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtGreen = sepiagreen;
            image[i][j].rgbtBlue = sepiablue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // outer loop over every row
    {
        for (int j = 0; j < width / 2; j++) // inner loop over every column
        {
            RGBTRIPLE swap = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = swap;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of image (second buffer variable)
    RGBTRIPLE imagecopy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagecopy[i][j] = image[i][j];
        }
    }
    // for each pixel (x, y) (nested for loop)
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            int start_x = (x - 1 < 0) ? 0 : x - 1;                 // set min x boundary
            int end_x = (x + 1 > width - 1) ? width - 1 : x + 1;   // set max x boundary
            int start_y = (y - 1 < 0) ? 0 : y - 1;                 // set min y boundary
            int end_y = (y + 1 > height - 1) ? height - 1 : y + 1; // set max y boundary

            // set initial variables for each pixel calculation/ adjustment
            int count = 0;
            double blur_red = 0;
            double blur_blue = 0;
            double blur_green = 0;

            for (int length = start_x; length <= end_x;
                 length++) // for every pixle grid x from start_x to end_x (within boundary)
            {
                for (int tall = start_y; tall <= end_y;
                     tall++) // for every pixel gird y from start_y to end_y (within boundary)
                {
                    blur_red = blur_red + imagecopy[length][tall].rgbtRed;
                    blur_blue = blur_blue + imagecopy[length][tall].rgbtBlue;
                    blur_green = blur_green + imagecopy[length][tall].rgbtGreen;
                    count++;
                }
            }

            blur_red = blur_red / count;
            blur_red = round(blur_red);
            image[x][y].rgbtRed = blur_red;

            blur_blue = blur_blue / count;
            blur_blue = round(blur_blue);
            image[x][y].rgbtBlue = blur_blue;

            blur_green = blur_green / count;
            blur_green = round(blur_green);
            image[x][y].rgbtGreen = blur_green;
        }
    }

    return;
}
