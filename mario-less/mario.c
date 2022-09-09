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
    while( height >= 1 && height <= 8 ) ;
        //printf(pyramid) ;

    int pyramid(void);
    {
        for(int row = 0; row < height; row++)
        {
            for(int column = 0; column < height; column++)
            {
                //printf("#") ;
                for(string hash = "#"  )
                {
                    printf("%s", hash) ;
                    hash++ ;
                }
                //printf("\n") ;
            }
                printf("\n") ;
        }
    }

}