#include <cs50.h>
#include <stdio.h>

void pyramid(void);

int main(void)
{
    int height, row, column;
    char h = '#';

    //Prompt user for input
    do
    {
        height = get_int("Height: ") ;
    }
    while( 1 >= height && height <= 8 ) ;
        //printf(pyramid) ;

    void pyramid(void);
    {
        //For each row
        for(row = 0; row < height; row++)
        {
            printf("\n") ;
            //For each column
            for(column = height; column <= height; column++)
            {
                printf("#");
            }
            //printf("#") ;
            //Move to newline
            //printf("\n") ;
        }
    }

}