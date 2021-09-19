#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int start_num;
    int end_num;

    //Prompt for start size
    do
    {
        start_num = get_int("Start size: ");
        printf("\n");
    } 
    while (start_num < 9);
    
    do
    {
        end_num = get_int("End size: ");
        printf("\n");
    } 
    while (end_num < start_num);
    
    //Calculate number of years until we reach threshold

    int years = 0;

    while (start_num < end_num)
    {
        start_num = start_num + start_num / 3 - start_num / 4;
        years++;

    //Print number of years
        printf("Years: %i\n", years);
    };
}