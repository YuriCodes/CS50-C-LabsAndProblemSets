#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompt user for input
    float change;
    
    do
    {
        change = get_float("Enter value: ");
    } while (change <= 0);
    
    //to convert cents to pennies

    int cents = round(change * 100);

    //logic to return the samllest amount of change

    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int coins = 0;

    //divide cents by the amounts set in variables
    //coins to keep track

    do
    {
        if (cents >= 25)
        {
            coins = cents / quarters;
            cents %= 25;
        }
        else if (cents >= 10)
        {
            coins = cents / dimes + coins;
            cents %= 10;
        }
        else if (cents >= 5)
        {
            coins = cents / nickels + coins;
            cents %= 5;
        }
        else 
        {
            coins = cents / pennies + coins;
            cents %= 1;
        }
        printf("\n");
    } while (cents !=0);
    
    printf("Amount: %i\n", coins);
}