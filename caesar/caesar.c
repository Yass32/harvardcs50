#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (only_digits(argv[1]) == true)
        printf("\n")
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


}

// Make main take only one arguement whereby it only accepts positive integers
// Condition for if no arguement or more than one argument is given print error

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            return true;
        }
        else
        {
            retrun false;
        }
    }
}