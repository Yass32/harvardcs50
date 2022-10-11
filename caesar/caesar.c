#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (only_digits(argv[1]) == true)
        {
            return 0;
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

    string argv[1] = atoi(argv[1]);
    string text = get_string("Plaintext: ");

    //for (int i = 0; i < strlen(text); i++)
    //{
    //   rotate(i, 1);
    //}



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
            return false;
        }
    }
    return 0;
}

char rotate(char c, int n);
{

    if(isaplha(c))
    {
        if(isupper(c))
        {
            int p = (int) c - 65;
            fjf
        }
        else if(islower(c))
        {
            f
        }
    }
    else
    {
        return c;
    }
}