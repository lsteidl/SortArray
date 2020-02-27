#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
//
// Generates array with random values (1-99), sorts elements, displays result to user
//
int main()
{

    int manual_array[10]; // define array to be sorted manually
    int qsort_array[10];  // define array to be sorted with built in function
    int random;           // hold random number
    srand(time(NULL));    // sets up new sequence of pseudo-random numbers to be returned by rand()
    for (int i = 0; i < 10; i++)
    {
        random = rand() % 100; // get only numbers between 0 and 99
        // fill both arrays
        qsort_array[i] = random;
        manual_array[i] = random;
    }
    // display array before sorting
    printf("Before sorting.....");
    for (int i = 0; i < 10; i++)
    {
        // handle punctuation for last element
        if (i == 9)
        {
            printf("%d\n", qsort_array[i]);
        }
        else
        {
            printf("%d, ", qsort_array[i]);
        }
    }

    qsort(qsort_array, 10, sizeof(int), compare); // built-in quicksort function

    // display array after quicksort
    printf("Quicksort Result...");
    for (int i = 0; i < 10; i++)
    {
        // handle punctuation for last element
        if (i == 9)
        {
            printf("%d\n", qsort_array[i]);
        }
        else
        {
            printf("%d, ", qsort_array[i]);
        }
    }

    // sort manually
    // loop through each array element
    int lowest = 100; // hold value of next lowest element
    int index = -1;   // hold index of next lowest element

    // iterate through array. each timeplacing next lowest
    for (int i = 0; i < 10; i++)
    {
        // loop to find next lowest element
        for (int j = i; j < 10; j++)
        {
            if (manual_array[j] < lowest)
            {
                lowest = manual_array[j];
                index = j;
            }
        }
        // switch lowest with value in next space to fill
        manual_array[index] = manual_array[i];
        manual_array[i] = lowest;
        lowest = 100; // reset so next lowest can be found
    }
    // display array after manual sorting
    printf("Manual Result......");
    for (int i = 0; i < 10; i++)
    {
        // handle punctuation for last element
        if (i == 9)
        {
            printf("%d\n", manual_array[i]);
        }
        else
        {
            printf("%d, ", manual_array[i]);
        }
    }

    return 0;
}