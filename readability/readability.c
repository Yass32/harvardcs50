#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);
int grade(int g);


int main(void)
{
    string input = get_string("Text: ");
    printf("%s\n", input);

    int L = (float) count_letters(input) / count_words(input) * 100 ;
    int S = (float) count_sentences(input) / count_words(input) * 100 ;
    int index = 0.0588 * L - 0.296 * S - 15.8 ;

    int number = round(index);
        if (number < 1 )
        {
            printf("Before Grade 1\n");
        }
        else if (number >= 16)
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
        for (int h = 0; h < strlen(input); h++)
        {
            if (isalpha(input[h]))
            {
                nu++;
            }
        }
        return nu;
    }

    int count_words(string input)
    {
        int num = 1;
        for (int i = 0; i < strlen(input); i++)
        {
            if (isspace(input[i]))
            {
                num++;
            }
        }
        return num;
    }

    int count_sentences(string input)
    {
        int j, numb = 0;
        for (j = 0; j < strlen(input); j++)
        {
            if (input[j] == '.' || input[j] == '?' || input[j] == '!')
            {
                numb++;
            }
        }
        return numb;
    }

    int grade(int g)
    {
        int number = round(g);
        if (number < 1 )
        {
            printf("Before Grade 1\n");
        }
        else if (number >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", number);
        }
        return 0;
    }
