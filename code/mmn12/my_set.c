/*
 * Program: set.c
 * ---------------
 * This program reads integers from the user and creates a set from them.
 * A set is a series of unique numbers. The program then prints out the
 * original input from the user and the created set 
 * Both in the order the numbers were input.
 */

#include <stdio.h>
#include <stdlib.h>

/* Initial size for reallocations */
#define INITIAL_SIZE sizeof(int)
/**
 * This macro resizes a dynamic array by a specified amount
 * Adds a constant to a variable to be used by realloc.
 *
 * @param current_size: the current size of the array
 * @param new_size: the amount to increase the size of the array by
 * @return the new size of the array
 */
#define ENLARGE_SIZE(current_size, new_size) (((new_size) > (current_size)) ? (new_size) : ((current_size) * INITIAL_SIZE))

/**
 * This function reads integers from standard input and stores them as a set of integers in a dynamic array.
 * The set will not contain any duplicates.
 *
 * @param set_ptr: a pointer to a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 * @param original_input_ptr: a pointer to a pointer to the set of integers - to print the original input
 * @param set_size: a pointer to the number of elements in the set - to print the original input
 */ 
void get_set(int **set_ptr, int *set_size,int **original_input_ptr, int *original_input_size);

/**
 * This function prints out a given integer set, ensuring that each number is printed only once.
 *
 * @param set A pointer to an integer set
 * @param set_size An integer representing the size of the set
 *
 * @return void
 */
void print_set(const int *set, int set_size);

/**
 * This function checks if a given number is present in a given integer set.
 *
 * @param set A pointer to an integer set
 * @param set_size An integer representing the size of the set
 * @param num The integer to search for in the set
 *
 * @return 1 if the number is in the set, 0 otherwise
 */
int in_set(const int *set, int set_size, int num);

int main() {
    int *set = NULL;
    int set_size = 0;
    int *original_input = NULL;
    int original_input_size = 0;
    printf("Enter a series of numbers (Ctrl+D to stop):\n");
    get_set(&set, &set_size, &original_input, &original_input_size); /* Get the set from the user */

    /* Print the original input */
    printf("This is the original input: ");
    print_set(original_input,original_input_size);


    if (set_size == 0) { /* Check if the set is empty */
        printf("The set is empty.\n");
    } else {
        printf("The required set is: ");
        print_set(set, set_size); /* Print the set */
    }

    /* Freeing allocated memory in the end of the program */
    free(original_input); 
    
    return 0;
}

/**
 * This function reads integers from standard input and stores them as a set of integers in a dynamic array.
 * The set will not contain any duplicates.
 *
 * @param set_ptr: a pointer to a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 * @param original_input_ptr: a pointer to a pointer to the set of integers - to print the original input
 * @param original_input_size: a pointer to the number of elements in the set - to print the original input
 */ 
void get_set(int **set_ptr, int *set_size,int **original_input_ptr, int *original_input_size){
    /* Initialize the set and set size */
    int num,i;
    int max_size = INITIAL_SIZE; /* Initialize maximum size of set */
    int *new_original_input_ptr = NULL; /* Initialize new pointer to keep track of address in memory */
    int *new_set_ptr = NULL; /* Initialize new pointer to keep track of address in memory */
    *set_ptr = NULL;  /* Initialize set pointer to NULL */
    *original_input_ptr = NULL;  /* Initialize set pointer to NULL */
    *set_size = 0;  /* Initialize set size to 0 */
    *original_input_size = 0;  /* Initialize orig set size to 0 */


    /* Initialize a set to keep track of which numbers have already been seen */
    *original_input_ptr = malloc(sizeof(int) * INITIAL_SIZE);
    if (*original_input_ptr == NULL) { /* Check whether allocation was successful */
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    /* Read integers from standard input and add them to the set */
    while (scanf("%d", &num) == 1) { /* Loop through input until end of file */
        /* Reallocate memory for the orig set if necessary */
        if (*original_input_size >= max_size) {
            max_size = ENLARGE_SIZE(max_size, *original_input_size); /* Increase the maximum size of set USING the MACRO*/
            new_original_input_ptr = (int *)realloc(*original_input_ptr, sizeof(int) * max_size); /* Reallocate memory for original_input */
            if (new_original_input_ptr == NULL) { /* Check whether allocation was successful */
                fprintf(stderr, "Error: Unable to allocate memory\n");
                exit(EXIT_FAILURE);
            }
            *original_input_ptr = new_original_input_ptr;  /* Update the pointer to the new memory address */
            }
        /* Add number to set of orig input */
        (*original_input_ptr)[(*original_input_size)++] = num;  
    }

    /* Allocate initial memory for the set */
    *set_ptr = malloc(sizeof(int) * INITIAL_SIZE);
    if (*set_ptr == NULL) { /* Check whether allocation was successful */
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < *original_input_size; i++) {
        /* Only add the number to the set if it is not already in the set */
        if (!in_set(*set_ptr, *set_size, (*original_input_ptr)[i])) {
            /* Reallocate memory for the new set if necessary */
            if (*set_size >= max_size) {
                max_size = ENLARGE_SIZE(max_size, *set_size); /* Increase the maximum size of set USING the MACRO*/
                new_set_ptr = (int *)realloc(*set_ptr, sizeof(int) * max_size); /* Reallocate memory for set */
                if (new_set_ptr == NULL) { /* Check whether allocation was successful */
                    fprintf(stderr, "Error: Unable to allocate memory\n");
                    exit(EXIT_FAILURE);
                }
                *set_ptr = new_set_ptr;  /* Update the pointer to the new memory address */
            }
            /* Add number to set */
            (*set_ptr)[(*set_size)++] = (*original_input_ptr)[i];
        }
    }
}

/**
 * This function prints a set of integers to the console.
 * The set is stored as a dynamic array.
 *
 * @param set: a pointer to the set of integers
 * @param set_size: the number of elements in the set
 */
void print_set(const int *set, int set_size) {
    int i;
    for (i = 0; i < set_size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

/**
 * This function checks if an integer is already in a set of integers.
 * The set is stored as a dynamic array.
 *
 * @param set: a pointer to the set of integers
 * @param set_size: the number of elements in the set
 * @param num: the integer to search for in the set
 * @return 1 if the integer is in the set, 0 otherwise
 */
int in_set(const int *set, int set_size, int num) {
    int i;
    for (i = 0; i < set_size; i++) {
        if (set[i] == num) {
            return 1;
        }
    }
    return 0;
}