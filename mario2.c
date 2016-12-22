/* Mario
* 
* Specification
* Write, in a file called mario.c in your directory, a program that recreates these half-pyramids using hashes (#) for blocks.
* To make things more interesting, first prompt the user for the half-pyramids' heights, a non-negative integer no greater than 23.
* If the user fails to provide a non-negative integer no greater than 23, you should re-prompt for the same again.
* Then, generate (with the help of printf and one or more loops) the desired half-pyramids.
* Take care to left-align the bottom-left corner of the left-hand half-pyramid with the left-hand edge of your terminal window.
*/

#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int i, j, k, l = 0;
    int height = get_positive_int();
    
    for(i=1; i<=height; i++)
    {
        for(j=0; j<height-i; j++)
        {
            printf(" ");
        }
        for(k=0; k<i; k++)
        {
            printf("#");
        }
        printf("  ");
        for(l=0; l<i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}

int get_positive_int(void)
{
    int height;
    
    do
    {
        printf("Enter height: ");
        height = get_int();
    }
    while((height > 23) || (height < 0));
    return height;
}