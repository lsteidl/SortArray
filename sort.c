#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
//
// Generates array with random values (1-99), sorts elements, displays result to user
//
int main()
{

    int manual_array[10];  // define array to be sorted manually
    int qsort_array[10];   // define array to be sorted with built in function
    // program decision input
    int input;             // holds user input
    char line[256];        // holds line retrieved by fgets()
    // custom array input
    char buffer[256];      // holds line retrieved by getline()
    char *b = buffer;      // pointer to getline() buffer
    size_t buffer_size = 256;
    int invalid_input = 1; // false only after valid input is read

    while (invalid_input)
    {
        printf("1) Generate Random Array\n");
        printf("2) Custom Array (user defined values)\n");
        printf("User Choice: ");

        fgets(line, sizeof(line), stdin);
        if (1 == sscanf(line, "%d", &input) && (input > 0 && input < 3))
        {
            printf("You choose: %d \n", input); // only for testing
            invalid_input = 0;                  // set to end while loop
        }
        else
        {
            printf("Input must be 1 or 2!\n");
        }
    }
    // Custom array from user input
    if (input == 2)
    {
        int read_size; // holds input line size
        char* token; // use for tokenization
        printf("Please enter 10 integers with values (1-99) seperated by commas...\n");
        read_size = getline(&b, &buffer_size, stdin);
        
        for (int i = 0; i < 10; i++)
        {
                if((token = strsep(&b, " ,")) != NULL){
                    qsort_array[i] = atoi(token);
                    manual_array[i] = atoi(token);
                    printf("You NOW choose: %d \n", atoi(token)); // only for testing
                    printf("added: %d", qsort_array[i]); // only for testing
                }
        }
    }
    // input == 1, Random Generation
    else
    {
        int random;        // hold random number
        srand(time(NULL)); // sets up new sequence of pseudo-random numbers to be returned by rand()
        for (int i = 0; i < 10; i++)
        {
            random = rand() % 100; // get only numbers between 0 and 99
            // fill both arrays
            qsort_array[i] = random;
            manual_array[i] = random;
        }
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