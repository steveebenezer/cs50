/* Initials (less comfortable)
* 
* Implement your program in a file called initials.c in a directory called initials.
* Your program should prompt a user for their name using get_string to obtain their name as a string.
* You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus single spaces between words. You don’t need to worry about names like Joseph Gordon-Levitt, Conan O’Brien, or David J. Malan!
* Your program should print the user’s initials (i.e., the first letter of each word in their name) with no spaces or periods, followed by a newline (\n).
*/

#include <stdio.h>
#include <cs50.h>

int capitalize(int);
int main()
{
    int i = 0;
    char *name = get_string();
    
    
    printf("%c", capitalize(name[0]));
    
    while(name[i] != '\0')
    {
        if(name[i] == ' ') {
            putchar(capitalize(name[i+1]));
        }
        i++;
    }
    printf("\n");
    return 0;
}

int capitalize(int c)
{
    if(c >= 97 && c <= 122) {
        return c - 32;
    }
    return c;
}