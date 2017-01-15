/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(value < 0) return false;
    for(int i = 0; i < n; i++) {
        if(values[i] == value) return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(values[j] < values[i]) {
                int temp = values[j];
                values[j] = values[i];
                values[i] = temp;
            }
        }
    }
    return;
}
