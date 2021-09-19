#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What is your name?\n");
    printf("Hello, %s\n", answer);
}