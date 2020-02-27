#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int compare(const void * a, const void * b){
    return(*(int*)a - *(int*)b);
}
//
// Generates array with random values (1-99), sorts elements, displays result to user
//
int main()
{
    
    int manual_array[10];       // define array to be sorted manually
    int qsort_array[10]; // define array to be sorted with built in function
    int random;          // hold random number
    srand(time(NULL));   // sets up new sequence of pseudo-random numbers to be returned by rand()
    for (int i = 0; i < 10; i++)
    {
        random = rand() % 100; // get only numbers between 0 and 99
       // printf("%d\n", random);
        array[i] = random;
    }
    // display array before sorting
    printf("Before sorting...");
    for (int i = 0; i < 10; i++)
    {
        
        if(i == 9){
            printf("%d\n", array[i]);
        }
        else{
            printf("%d, ", array[i]);
        }
    }
    qsort(array, 10, sizeof(int), compare); // built-in quicksort function

    // display array after quicksort 
    printf("Quicksort Result...");
    for (int i = 0; i < 10; i++)
    {
        
        if(i == 9){
            printf("%d\n", array[i]);
        }
        else{
            printf("%d, ", array[i]);
        }
    }
    
    return 0;
}