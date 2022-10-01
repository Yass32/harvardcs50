#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    string input = get_string("Text: ");
    printf("%s\n", input);
    printf("%i letters\n", round(index));
    printf("%i words\n", count_words(input));
    printf("%i sentences\n", count_sentences(input));

    int L = (float)count_letters(input) / count_words(input) * 100
    int S = (float)

    int index = 0.0588 * L - 0.296 * S - 15.8
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
