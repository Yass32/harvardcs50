#include <cs50.h>
#include <stdio.h>

/*int main(void)
{
    int height, row, column;

    //Prompt user for input
    do
    {
        height = get_int("Height: ") ;
    }
    while( 1 >= height && height <= 8 ) ;

    //For each row
    for(row = 1; row <= height; row++)
    {
        //For each column
        for(column = height; column < 0; column--)
        {
            //Print brick
            if(column > row)
            {
                printf(".");
            }
            else
            {
                printf("#");
            }
        }
        //Move to newline
        printf("\n") ;
    }
} */

int main(void)
{
    int answer = get_int("Input Size ") ;

    for(int row = 1; row <= 4; row++)
    {
        for(int column = 4; column > 0 ; column--)
        {
            if(column > row)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}