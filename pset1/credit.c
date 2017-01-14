/* Credit
*
* In credit.c, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein.
* So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less, and that main always return 0.
* For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).
* Do not assume that the user’s input will fit in an int! Best to use get_long_long from CS50’s library to get users' input. (Why?)
*
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int checksum(long long, int);
int getDigit(long long, int);

int main(void)
{
    // Initialize credit card number
    long long cc;
    
    // Make sure to get a positive number
    printf("Enter card: ");
    do
    {
        cc = get_long_long();
        if(cc < 0) printf("Invalid! Retry: \n");
        break;
    }
    while (cc < 0);
    
    // Get the length of digits
    int len = floor(log10(llabs(cc))+1);
    
    switch(checksum(cc, len)) 
    {
        case 1: printf("VISA\n");
            break;
        case 2: printf("MASTERCARD\n");
            break;
        case 3: printf("AMEX\n");
            break;
        default: printf("INVALID\n");
    }
    
    return 0;
}

int checksum(long long cc, int len)
{
    int buffer[len], i;
    int sum = 0;
    
    // Store each digit of card into array
    for(i=0;i<len;i++)
    {
        buffer[i] = getDigit(cc, i);
    }
    
    // Add every other number and store the sum
    for(i=0; i<len; i++)
    {
        if(i%2) {
            if(buffer[i]<5) {
                sum += buffer[i] * 2;
            } else {
                // Split and Add, if number * 2 is > 9
                sum += (buffer[i] * 2) - 9;
            }
        } else {
            continue;
        }
    }
    
    // Add the left out digits to sum
    for(i=0;i<len;i++)
    {
        if(!(i%2)) {
            sum += buffer[i];
        } else {
            continue;
        }
    }
    
    // Check if the sum's last digit is 0
    int valid = sum % 10;
    
    // Store the first two digits of card
    int startDigit = buffer[len-2] + buffer[len-1]*10;
    
    // printf("%d %d %d\n", startDigit, len, valid);
    
    // Validate if AMEX or MasterCard or Visa
    if(buffer[len-1] == 4 && (len == 13 || len == 16) && !valid) {
        return 1;
    } else if((startDigit >= 51 || startDigit <= 55) && len == 16 && !valid) {
        return 2;
    } else if((startDigit == 37 || startDigit == 34) && len == 15 && !valid) {
        return 3;
    } else {
        return 0;
    }
    
    return 0;
}

// Split digits
int getDigit(long long cc, int i)
{
    double temp = (double) cc;
    
    for(int j=0; j<=i; j++)
    {
        temp = ((long long) temp) / 10.0;
    }
    
    double temprec = (long long) temp;
    
    int digit = round((temp - temprec)*10);
    return digit;
}