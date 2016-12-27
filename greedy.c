/* Greedy
*
* Write, in a file called greedy.c in your ~/workspace/pset1/ directory, a program that first asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made.
* Use get_float from the CS50 Library to get the user’s input and printf from the Standard I/O library to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
* We ask that you use get_float so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be 9.75 and not $9.75 or 975. However, if some customer is owed $9 exactly, assume that your program’s input will be 9.00 or just 9 but, again, not $9 or 900. Of course, by nature of floating-point values, your program will likely work with inputs like 9.0 and 9.000 as well; you need not worry about checking whether the user’s input is "formatted" like money should be.
* You need not try to check whether a user’s input is too large to fit in a float. Using get_float alone will ensure that the user’s input is indeed a floating-point (or integral) value but not that it is non-negative.
* If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.
* Incidentally, so that we can automate some tests of your code, we ask that your program’s last line of output be only the minimum number of coins possible: an integer followed by \n.
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25;
#define DIME 10;
#define NICKEL 5;

int main(void) 
{
    // Variable declarations
    float given_amount = 0;
    int cent_amount = 0;
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int leftover = 0;
    int coin_count = 0;
    
    //Input handling
    do 
    {
        printf("You gave me: ");
        given_amount = GetFloat();
        //If given amount is zero or less then zero checked
        if(given_amount == 0||given_amount <= 0)
        printf("Number Should be greater then Zero EG:10\n:");
    }
    while(given_amount <= 0);

    // Given amount is convert to cents
    cent_amount = (int)round(given_amount*100);

    // Quarters
    quarter_count = cent_amount / QUARTER;
    leftover = cent_amount % QUARTER;
    
    // Dimes
    dime_count = leftover / DIME;
    leftover = leftover % DIME;
    
    // Nickels
    nickel_count = leftover / NICKEL;
    leftover = leftover % NICKEL;
    
    // Leftover at this stage is pennies
    coin_count = quarter_count + dime_count + nickel_count + leftover;
    
    // Pretty print
    // printf("You get %d coins: %d quarters, %d dimes, %d nickels and %d pennies.\n", coin_count, quarter_count, dime_count, nickel_count, leftover);
    
    //Required output:
    printf("%d\n", coin_count);
    
    return 0;
}
/*
#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    float change;
    int count = 0;
    
    printf("O hai! How much change is owed?\n");
    change = get_positive_float();
    do
    {
        change = get_float();
        if(change<=0) printf("\nRetry: ");
    }
    while(change <= 0);
    change = round(change * 100.0);
    
    while(change > 0.24) {
        count++;
        change -= 0.25;
    }
    while(change > 0.9)
    {
        count++;
        change -= 0.10;
    }
    while(change > 0.04)
    {
        count++;
        change -= 0.05;
    }
    while(change < 0.5)
    {
        count++;
        change -= 0.01;
    }
    
    printf("%i", count);
    return 0;
}

float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float();
        if(n<=0) printf("\nRetry: ");
    }
    while(n <= 0);
    
    n = round(n * 100.0);
    return n;
}*/