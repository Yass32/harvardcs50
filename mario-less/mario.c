#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column;

    //Prompt user for input
    do
    {
        height = get_int("Height: ") ;
    }
    while( height >= 1 && height <= 8 ) ;

    //For each row
    for(row = 1; row <= height; row++)
    {
        //For each column
        for(column = height; column > 0; column--)
        {
            //Print brick
            if(column > row)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        //Move to newline
        printf("\n") ;
    }
}