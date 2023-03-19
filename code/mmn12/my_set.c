/*
 * Program: set.c
 * ---------------
 * This program reads integers from the user and creates a set from them.
 * A set is a series of unique numbers. The program then prints out the
 * set in the order the numbers were input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This macro resizes a dynamic array by a specified amount
 * Adds a constant to a variable to be used by realloc.
 *
 * @param x: the current size of the array
 * @param c: the amount to increase the size of the array by
 * @return the new size of the array
 */
#define INITIAL_SIZE 2
#define ENLARGE_SIZE(s, n) (((n) > (s)) ? (n) : ((s) * INITIAL_SIZE))

/**
 * This function reads integers from standard input and stores them as a set of integers in a dynamic array.
 * The set will not contain any duplicates.
 *
 * @param set_ptr: a pointer to a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 */ 
void get_set(int **set_ptr, int *set_size);

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
 * This helper function checks if a given number is present in a given integer set.
 *
 * @param set A pointer to an integer set
 * @param set_size An integer representing the size of the set
 * @param num The integer to search for in the set
 *
 * @return 1 if the number is in the set, 0 otherwise
 */
int in_set(const int *set, int set_size, int num);

/* main: runs the get_set and print_set functions. */
int main() {
    int *set = NULL;
    int set_size = 0;
    printf("Enter a series of numbers (Ctrl+D to stop):\n");
    get_set(&set, &set_size); /* Get the set from the user */
    if (set_size == 0) { /* Check if the set is empty */
        printf("The set is empty.\n");
    } else {
        printf("The set is: ");
        print_set(set, set_size); /* Print the set */
    }

    free(set); /* Free the memory allocated for the set */
    return 0;
}

/**
 * This function reads integers from standard input and stores them as a set of integers in a dynamic array.
 * The set will not contain any duplicates.
 *
 * @param set_ptr: a pointer to a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 */ 
void get_set(int **set_ptr, int *set_size) {
    /* Initialize the set and set size */
    int num, max_size;
    *set_ptr = NULL;  /* Initialize set pointer to NULL */
    *set_size = 0;  /* Initialize set size to 0 */

    /* Allocate initial memory for the set */
    *set_ptr = malloc(sizeof(int) * INITIAL_SIZE);
    if (*set_ptr == NULL) { /* Check whether allocation was successful */
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    max_size = INITIAL_SIZE; /* Initialize maximum size of set */

    /* Read integers from standard input and add them to the set */
    while (scanf("%d", &num) == 1) { /* Loop through input until end of file */
        /* Only add the number to the set if it is not already in the set */
        if (!in_set(*set_ptr, *set_size, num)) {
            /* Reallocate memory for the set if necessary */
            if (*set_size == max_size) {
                max_size *= INITIAL_SIZE; /* Multiply the maximum size of set by INITIAL SIZE*/
                *set_ptr = realloc(*set_ptr, sizeof(int) * max_size); /* Reallocate memory for set */
                if (*set_ptr == NULL) { /* Check whether allocation was successful */
                    fprintf(stderr, "Error: Unable to allocate memory\n");
                    exit(EXIT_FAILURE);
                }
            }
            (*set_ptr)[*set_size] = num;
            (*set_size)++;
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
    int i, j;
    for (i = 0; i < set_size; i++) {
        int seen = 0;
        for (j = 0; j < i; j++) {
            if (set[i] == set[j]) {
                seen = 1;
                break;
            }
        }
        if (!seen) { /* If the element has not already been seen, print it */
            printf("%d ", set[i]);
        }
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