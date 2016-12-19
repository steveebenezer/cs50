/* Mario

* Specification
* Write, in a file called mario.c directory, a program that recreates this half-pyramid using hashes (#) for blocks.
* To make things more interesting, first prompt the user for the half-pyramid’s height, a non-negative integer no greater than 23.
* If the user fails to provide a non-negative integer no greater than 23, you should re-prompt for the same again.
* Then, generate (with the help of printf and one or more loops) the desired half-pyramid.
* Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.
*/

#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int i, j, k = 0;
    int height = get_positive_int();
    
    for(i=1; i<=height; i++)
    {
        for(j=0; j<height-i+1; j++)
        {
            printf(" ");
        }
        for(k=0; k<i+1; k++)
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
    while((height > 8) || (height < 0));
    return height;
}