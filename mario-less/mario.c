#include <cs50.h>
#include <stdio.h>

int pyramid(void);

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ") ;
    }
    while( 1 >= h && h <= 8 ) ;
        //printf(pyramid) ;

    int pyramid(void);
    {
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < (h + 1); j++)
            {
                printf("#\n") ;
            }
                //printf("\n") ;
        }
    }

}