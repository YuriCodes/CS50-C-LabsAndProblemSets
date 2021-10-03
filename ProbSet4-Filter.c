#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Rows
    for (int i = 0; i < height; i++)
    {
        //Columns
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            
            //In gray all three rgb values must be the same
            //Calculate average and round it in case is not an int
        
            int average = round((red + green + blue) / 3);
            
            //Set each of the color values to the average
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Rows
    for (int i = 0; i < height; i++)
    {
        //Columns
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            //Calculate each color and apply sepia formula
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
        
            //Check if it goes over 255
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
                //assign new value to it
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else 
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
        
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else 
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
       
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Rows
    for (int i = 0; i < height; i++)
    {
        //Columns
        for (int j = 0; j < (width / 2); j++)
        {
            //Store the original image in a variable
            int redT = image[i][j].rgbtRed;
            int greenT = image[i][j].rgbtGreen;
            int blueT = image[i][j].rgbtBlue;
            
            //Flip the normal image to a reversed one
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            
            //Equal the normal image to the reversed result
            image[i][width - j - 1].rgbtRed = redT;
            image[i][width - j - 1].rgbtGreen = greenT;
            image[i][width - j - 1].rgbtBlue = blueT;
            
        }
    }
    return;
}

// Blur image
// Box blur
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Temporal image 
    RGBTRIPLE temp[height][width];
    
    //Rows
    for (int i = 0; i < height; i++)
    {
        //Columns
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            float counter = 0.00;
            
            //figure out pixels around 
            //check behind it and after it
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    //Store it
                    int current_Xpixel = i + x;
                    int current_Ypixel = j + y;
                    
                    //See if it's valid and it doesn't go over the limits
                    if (current_Xpixel < 0 || current_Xpixel > (height - 1) || current_Ypixel < 0 || current_Ypixel > (width - 1))
                    {
                        continue;
                    }
                    
                    //Store the image pixel values
                    red += image[current_Xpixel][current_Ypixel].rgbtRed;
                    green += image[current_Xpixel][current_Ypixel].rgbtGreen;
                    blue += image[current_Xpixel][current_Ypixel].rgbtBlue;
                    
                    counter++;
                }
                //Average the pixel values (incluiding the current color) now
                temp[i][j].rgbtRed = round(red / counter);
                temp[i][j].rgbtGreen = round(green / counter);
                temp[i][j].rgbtBlue = round(blue / counter);
            }
        }
    }
    
    //Copy the blured one to the original image
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
