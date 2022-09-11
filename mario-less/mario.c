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

    //For each row
    for(row = 1; row <= height; row++)
    {
        //For each column
        for(column = 1; column <= row; column++)
        {
            //Print brick
            printf("°");
        }
        //Move to newline
        printf("\n") ;
    }
}