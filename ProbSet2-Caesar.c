#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

//if it's more than two inputs
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
 
//declare length and key 
    int length = strlen(argv[1]);
//convert the string into an int with atoi
    int key = atoi(argv[1]);
    
    
//check if it's a letter
    for (int i = 0; i < length; i++)
    {   
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        if (!isdigit(argv[1][i]))
        {
            printf("Invalid key\n");
            return 1;
        }
    }
      
      
//if it's a number prompt user for text to cypher
//first the character text[j] into an int
//use the formula for the caesar cypher 
//print resulting characters stored in c
    for (int i = 0; i < length; i++)
    { 
        if (isdigit(argv[1][i]) != 0)
        {
            string text = get_string("Plain text:");
            int txt_length = strlen(text);
            string cypher = text;
            for (int j = 0; j < txt_length; j++)
            {
                int c = 0;
                
                if (isupper(text[j]))
                {
                    c = (((int)text[j] - 65 + key) % 26);
                    cypher[j] = c + 65;  
                    
                }
                else if (islower(text[j]))
                {
                    c = (((int)text[j] - 97 + key) % 26);
                    cypher[j] = c + 97;
                }
            } 
            printf("ciphertext: %s", cypher);
            printf("\n");
            return 0;
        }
    }
} 
