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
#define INITIAL_SIZE sizeof(int)
#define ENLARGE_SIZE(s, n) (((n) > (s)) ? (n) : ((s) * INITIAL_SIZE))

/**
 * This function reads integers from standard input and stores them as a set of integers in a dynamic array.
 * The set will not contain any duplicates.
 *
 * @param set_ptr: a pointer to a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 * @param orig_set_ptr: a pointer to a pointer to the set of integers - to print the original input
 * @param set_size: a pointer to the number of elements in the set - to print the original input
 */ 
void get_set(int **set_ptr, int *set_size,int **orig_set_ptr, int *orig_set_size);

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

/* main: runs the get_set and print_set functions. */
int main() {
    int *set = NULL;
    int set_size = 0;
    int *orig_set = NULL;
    int orig_set_size = 0;
    printf("Enter a series of numbers (Ctrl+D to stop):\n");
    get_set(&set, &set_size, &orig_set, &orig_set_size); /* Get the set from the user */
    
    return 0;
}

/**
 * This function reads integers from standard input and stores them as a set of integers in a dynamic array.
 * The set will not contain any duplicates.
 *
 * @param set_ptr: a pointer to a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 * @param orig_set_ptr: a pointer to a pointer to the set of integers - to print the original input
 * @param orig_set_size: a pointer to the number of elements in the set - to print the original input
 */ 
void get_set(int **set_ptr, int *set_size,int **orig_set_ptr, int *orig_set_size){
    /* Initialize the set and set size */
    int num;
    int max_size = INITIAL_SIZE; /* Initialize maximum size of set */
    *set_ptr = NULL;  /* Initialize set pointer to NULL */
    *orig_set_ptr = NULL;  /* Initialize set pointer to NULL */
    *set_size = 0;  /* Initialize set size to 0 */
    *orig_set_size = 0;  /* Initialize orig set size to 0 */

    printf("going to malloc set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),set_ptr);
    /* Allocate initial memory for the set */
    *set_ptr = malloc(sizeof(int) * INITIAL_SIZE);
    printf("malloced set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),set_ptr);
    if (*set_ptr == NULL) { /* Check whether allocation was successful */
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    printf("going to malloc orig_set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),orig_set_ptr);
    /* Initialize a set to keep track of which numbers have already been seen */
    *orig_set_ptr = malloc(sizeof(int) * INITIAL_SIZE);
    printf("malloced orig_set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),orig_set_ptr);
    if (*orig_set_ptr == NULL) { /* Check whether allocation was successful */
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    /* Read integers from standard input and add them to the set */
    while (scanf("%d", &num) == 1) { /* Loop through input until end of file */
        /* Reallocate memory for the orig set if necessary */
        if (*orig_set_size >= max_size) {
            max_size = ENLARGE_SIZE(max_size, *orig_set_size); /* Increase the maximum size of set USING the MACRO*/
            printf("going to realloc orig_set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),orig_set_ptr);
            *orig_set_ptr = realloc(*orig_set_ptr, sizeof(int) * max_size);
            if (*orig_set_ptr == NULL) {
                fprintf(stderr, "Error: Unable to allocate memory\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("this is *orig_set_size %p\n",*orig_set_size);
        (*orig_set_ptr)[(*orig_set_size)++] = num;
        
        /* Only add the number to the set if it is not already in the set */
        if (!in_set(*set_ptr, *set_size, num)) {
            /* Reallocate memory for the new set if necessary */
            if (*set_size >= max_size) {
                max_size = ENLARGE_SIZE(max_size, *set_size); /* Increase the maximum size of set USING the MACRO*/
                printf("going to realloc set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),set_ptr);
                *set_ptr = realloc(*set_ptr, sizeof(int) * max_size); /* Reallocate memory for set */
                if (*set_ptr == NULL) { /* Check whether allocation was successful */
                    fprintf(stderr, "Error: Unable to allocate memory\n");
                    exit(EXIT_FAILURE);
                }
            }
            printf("this is *set_size %p\n",*set_size);
            (*set_ptr)[(*set_size)++] = num;
        }
    }

    /* Print the original input */
    printf("This is the original input: ");
    print_set(*orig_set_ptr,*orig_set_size);


    if (*set_size == 0) { /* Check if the set is empty */
        printf("The set is empty.\n");
    } else {
        printf("The required set is: ");
        print_set(*set_ptr, *set_size); /* Print the set */
    }

    
    printf("going to free set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),*set_ptr);
    free(*set_ptr); /* Free the memory allocated for the set if its not free*/
    printf("going to free set %d %p\n",(int)(sizeof(int) * INITIAL_SIZE),*orig_set_ptr);
    free(*orig_set_ptr);
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