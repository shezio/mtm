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
#define ENLARGE_SIZE(x, c) ((x) + (c))
#define INITIAL_SIZE 10


/**
 * This function dynamically grows an integer set while taking input from the user and
 * ensures that each number is unique.
 *
 * @param set A pointer to a pointer to an integer set
 * @param set_size A pointer to an integer representing the size of the set
 *
 * @return void
 */
void get_set(int **set, int *set_size);

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
    printf("Enter a series of numbers (Ctrl+D to stop):\n");
    get_set(&set, &set_size); /* Get the set from the user */
    printf("The set is: ");
    print_set(set, set_size); /* Print the set */
    free(set); /* Free the memory allocated for the set */
    return 0;
}

/**
 * This function prompts the user to enter integers and adds them to a set.
 * The set is stored as a dynamic array.
 *
 * @param set: a pointer to the set of integers
 * @param set_size: a pointer to the number of elements in the set
 */
void get_set(int **set, int *set_size) {
    int *set_ptr = NULL; /* Pointer to the dynamically allocated set */
    int size = 0;        /* The number of elements currently in the set */
    int capacity = 0;    /* The maximum number of elements the set can hold */
    int num;            /* Current number being read from input */
    int sign = 1; /* Sign of the current number */
    int c; /* First and Current characters being read from input */

    while ((c = getchar()) != EOF) {  /* loop until end of file is reached */
        if (c == '-') {  /* check if the character is a minus sign */
            sign = -1;  /* if it is, set the sign to negative */
        } else if (c >= '0' && c <= '9') {  /* check if the character is a digit */
            num = num * 10 + c - '0';  /* if it is, add the digit to the number */
        } else if (c == ' ' || c == '\t' || c == '\n') {  /* check if the character is whitespace */
            num *= sign;  /* if it is, multiply the number by the sign to get the final value */
            sign = 1;  /* reset the sign to positive */
            if (size == capacity) { /* If the set is full, allocate more memory for it */
                capacity = ENLARGE_SIZE(capacity, 10);
                set_ptr = realloc(set_ptr, capacity * sizeof(int)); /* Reallocate memory for the set */
                if (set_ptr == NULL) { /* If there was an error, exit the program */
                    printf("Error: out of memory.\n");
                    exit(1);
                }
            }
            /* If the set is empty or the current number is not already in the set, add it to the set */
            if (*set_size == 0 || !in_set(*set, *set_size, num)) {
                set_ptr[size] = num;
                size++;
                *set_size = *set_size + 1;
            }
        }
    }
    *set = set_ptr; /* Set the pointer to the set to the newly allocated memory */
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