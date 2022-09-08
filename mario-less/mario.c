#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int s;
    do
    {
        s = get_int("Height: ") ;
    }
    while( 1 >= s && s <= 8 ) ;
        printf("Stored: %i\n", s) ;

    for(int i = 0; i < s; i++)
    {
        printf("#\n") ;
        
    }


}