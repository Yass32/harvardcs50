#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int s;
    do
    {
        s = get_int("Height: ") ;
    }
    while( s > 0 && s < 9 )
        printf("Stored: %i\n", s) ;

    
}