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
    printf("%i letters\n", count_letters(input));
    printf("%i words\n", count_words(input));
    //printf("%i sentences\n", count_sentences);
}

    length = strlen(input);

    int count_letters(string input)
    {
        for (int h = 0; h < length; h++)
        {
            if (isalpha(input[h]))
            {
                int nu = 0;
                nu++;
            }
        }
        return nu;
    }

    int count_words(string input)
    {
        int num = 0;
        for (int i = 0; i < lenght; i++)
        {
            if (input[i] == " ")
            {
                num++;
            }
        }
        return num;
    }

    /*int count_sentences(string input)
    {
        int j, numb = 0;
        for (j = 0; j < strlen(input); j++)
        {
            if (input[i] == "." || "!" || "?")
            {
                numb++;
            }
        }
        return numb;
    }*/
