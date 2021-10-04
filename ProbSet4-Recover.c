#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//define BYTE struct
//8-bit unsigned integer
typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    //Error handling
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }
    else 
    {
        char *input_file_name = argv[1];
        //Open the file in read 'r' mode and store it in FILE
        FILE *input = fopen(input_file_name, "r");
        
        if (input == NULL)
        {
            printf("Error: cannot open %s\n", input_file_name);
            return 1;
        }
    
    
        //Declare buffer array 
        BYTE buffer[512];
        //Keep count of recovered images
        int count = 0;
        //To write in
        FILE *img = NULL;
        //Store the names here
        char file[8];
    
        //Do this until the end of the image card
        while (fread(&buffer, 512, 1, input) == 1)
        {
            //If it's the header of a new JPEG file
            //Use bitwise manipulation to check for the variants in the 4th byte
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //if it's a new header close the file and open a new one and get to work again
                if (!(count == 0))
                {
                    fclose(img);
                }
            
                //Use sprintf to print a string the file name
                sprintf(file, "%03i.jpg", count);
                img = fopen(file, "w");
                count++;
            }
        
            //If found write to the file
        
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
    
        fclose(input);
        fclose(img);
        return 0;
    
    }
}