#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    string input = get_string("Text: ");

    int L = (float) count_letters(input) / count_words(input) * 100 ;
    int S = (float) count_sentences(input) / count_words(input) * 100 ;
    float index = 0.0588 * L - 0.296 * S - 15.8 ;
    // Coleman-Liau index to calculate readability of a text.


    int number = round(index); //Using round to approximate index to the nearest int.

    if (number < 1) //Conditions depending on the value of the rounded index.
    {
        printf("Before Grade 1\n");
    }
    else if (number > 16 || number == 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", number);
    }

}

int count_letters(string input)
{
    int nu = 0;
    for (int h = 0; h <= strlen(input); h++)
    {
        if (isalpha(input[h]))
        {
            nu++;
        }
    }
    return nu;
}
//Function to count number of letters by incrementing everytime alphabet is detected

int count_words(string input)
{
    int num = 1;
    for (int i = 0; i <= strlen(input); i++)
    {
        if (isspace(input[i]))
        {
            num++;
        }
    }
    return num;
}
//Function to count number of words by incrementing everytime space is detected

int count_sentences(string input)
{
    int j, numb = 0;
    for (j = 0; j <= strlen(input); j++)
    {
        if (input[j] == '.' || input[j] == '?' || input[j] == '!')
        {
            numb++;
        }
    }
    return numb;
}
//Function to count number of sentences by incrementing everytime period exclamation or question mark is detected