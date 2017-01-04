/* Vigenère’s cipher
* 
* Implement your program in a file called vigenere.c in a directory called vigenere.
* Your program must accept a single command-line argument: a keyword, k, composed entirely of alphabetical characters.
* If your program is executed without any command-line arguments, with more than one command-line argument, or with one command-line argument that contains any non-alphabetical character, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).
* Otherwise, your program must proceed to prompt the user for a string of plaintext, p, (as by a prompt for plaintext:) which it must then encrypt according to Vigenère’s cipher with k, ultimately printing the result (prepended with ciphertext:) and exiting, with main returning 0.
* With respect to the characters in k, you must treat A and a as 0, B and b as 1, …​ , and Z and z as 25.
* Your program must only apply Vigenère’s cipher to a character in p if that character is a letter. All other characters (numbers, symbols, spaces, punctuation marks, etc.) must be outputted unchanged. Moreover, if your code is about to apply the jth character of k to the ith character of p, but the latter proves to be a non-alphabetical character, you must wait to apply that jth character of k to the next alphabetical character in p; you must not yet advance to the next character in k.
* Your program must preserve the case of each letter in p.
*
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i, n, j;
    
    // Validate length of arguments
    if(argc != 2) {
        printf("Usage: ./caeser k\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);
    
    // Convert key to alphabetical order
    for(i = 0; i <= keylen; i++)
    {
        if(isupper(key[i])) {
            key[i] = (key[i] - 65) % 26;
        } else if(islower(key[i])) {
            key[i] = (key[i] - 97) % 26;
        } else if(isdigit(key[i])) {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    
    // Get plain text
    string text = get_string();
    
    // Cipher the plain text
    for(i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if(isupper(text[i])) {
            printf("%c", ((text[i] - 65 + key[j]) % 26) + 65);
            j = (j + 1) % keylen;
        } else if(islower(text[i])) {
            printf("%c", text[i] = ((text[i] - 97 + key[j]) % 26) + 97);
            j = (j + 1) % keylen;
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    
    return 0;

}