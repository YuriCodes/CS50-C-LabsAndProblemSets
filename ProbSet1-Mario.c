#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
//Get input from user 
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
    
//For rows

    for (int i = 0; i < height; i++)
    {
//For the dots and then spaces before hashtags
    for (int j = height - 1; j > i; j--)
    {
        printf(" ");
    }
//For columns
    for (int k = 0; k <= i; k++)
    {
        printf("#");
    }
//New line
        printf("\n");
    }
};