#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(void)
{
    string input = get_string("Text: ");
    printf("%s\n", input);

    int count_letters(string input)
    {
        printf("%i/n", strlen(text));
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
        printf("%i\n", num);
    }

}