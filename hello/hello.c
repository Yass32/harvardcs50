#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask user for name
    string name = get_string("What's your name? ") ;
    //Print out name
    printf("hello, %s\n", name) ;
}