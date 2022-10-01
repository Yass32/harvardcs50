#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string input);
int count_words(string input);

int main(void)
{
    string input = get_string("Text: ");
    printf("Text: %s\n", input);
    printf("%i letters\n", count_letters);
    printf("%i words\n", count_words);
    printf("%i sentences\n", count_sentences);

    int count_letters(string input)
    {
        return strlen(input);
    }

    int count_words(string input)
    {
        int i, num;
        for (i = 0; i < strlen(input); i++)
        {
            if (input[i] == " ")
            {
                num++;
            }
        }
        return num;
    }

    int

}