#include <cs50.h>
#include <stdio.h>

int pyramid(void);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ") ;
    }
    while( 1 >= height && height <= 8 ) ;
        //printf(pyramid) ;

    int pyramid(void);
    {
        for(int row = 0; row < height; row++)
        {
            for(int hash = 0; hash < height; hash++)
            {
                //string s = "#" ;
                //printf("%s", s) ;
                printf("#\n") ;

            }
                string s = "#" ;
                printf("%s", s) ;
                s++;
                printf("n") ;
        }
    }

}