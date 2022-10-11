#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    if (argc == 2) // Make sure program was run with just one command-line argument
    {
        if (only_digits(argv[1]) == true) // Convert argv[1] from a `string` to an `int`
        {
            string text = get_string("Plaintext:  ");  // Prompt user for plaintext

            printf("Ciphertext: ");
            for (int i = 0; i < strlen(text); i++)  // For each character in the plaintext:
            {
                int sum = rotate(text[i], atoi(argv[1]));  // Rotate the character if it's a letter
                printf("%c", sum);
            }
            printf("\n");

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }





}

// Make main take only one arguement whereby it only accepts positive integers
// Condition for if no arguement or more than one argument is given print error

bool only_digits(string s) // Make sure every character in argv[1] is a digit
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}

char rotate(char c, int k)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int p = (int) c - 65;
            int ans = (p + k) % 26;
            return ans + 65;
        }
        else if (islower(c))
        {
            int p = (int) c - 97;
            int ans = (p + k) % 26;
            return ans + 97;
        }
    }
    else
    {
        return c;
    }
    return 0;
}