#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define RAND_MAX 99; // max range for random number
//
// Generates array with random values (1-99), sorts elements, displays result to user
//
int main()
{
    
   // int array[10];       // define array
    int random;          // hold random number
    srand(time(NULL));   // sets up new sequence of pseudo-random numbers to be returned by rand()
    for (int i = 0; i < 10; i++)
    {
        random = rand() % 100; // get only numbers between 0 and 99
        printf("%d\n", random);
    }
    
    
    return 0;
}