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

    //Create function that builds the bricks
    void pyramid(void);
    {
        //For each row
        for(row = 0; row < height; row++)
        {
            //For each column
            for(column = 0; column <= row; column++)
            {
                //Print brick
                printf("#");
            }
            //Move to newline
            printf("\n") ;
        }
    }
}