#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    } 
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int length = strlen(word);
    int score = 0;

    for (int i = 0; i < length; i++)
    {
    //ASCII value of letter A minus the word[i] character to get the index in POINTS
    //if it's the letter E (ASCII-69) and A (ASCII-65)
    //69-64 index of POINTS[4] so E its 1 point;
    //we check for upper and lowercase characters

        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 65]; //ASCII letter 'A'
        }
        else if (islower(word[i])){
            score += POINTS[word[i] - 97]; //ASCII letter 'a'
        }
    }
    return score; 
}