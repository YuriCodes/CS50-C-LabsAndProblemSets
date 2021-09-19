#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string sentence = get_string("Text: ");

    //printf("%s\n", sentence);

    //calculate letters, words and sentences

    int length = strlen(sentence);
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(sentence[i]))
        {
            letters++;
        }
        else if (isblank(sentence[i]))
        {
            words++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentences++;
        }
    }
    //calculate which grade is it from with the Coleman-Liau index formula

    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        prinf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}