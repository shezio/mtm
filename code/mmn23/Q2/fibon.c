/*
 * C program to create a circular linked list representing the Fibonacci series of a given length n,
 * prints it to the console and writes it to a file.
 *
 * The program accepts a file name as a command line argument, and interactively gets an unsigned integer n from the user.
 * It checks for error conditions such as invalid argument amount, file couldn't be opened, memory allocation failed, and negative input.
 *
 * The program frees the memory used by the linked list and closes the file before exiting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int main(int argc, char *argv[]) {
    Node *head = NULL;  /* Pointer to the beginning of the list */
    unsigned int n, i;  /* Initialize index variables and Fibo series length variable*/
    char input[256];    /* Input string for reading user input */
    FILE *fp;           /* File pointer to write to output file */
    
    /* Check if file name was given */
    if (argc != 2) {
        printf("Invalid number of arguments.\n");
        return 1;
    }
    /* Attempt to open the file */
    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("File couldn't be opened - Permission denied or there is no such file. \n");
        return 1;
    }
    
    /* Get user input interactively*/
    printf("Please enter a positive integer as the length of the Fibonnacci series to calculate: ");
    fgets(input, 256, stdin);

    /* Input validations */
    if (sscanf(input, "%u", &n) != 1) {
        printf("Invalid input format. Please enter a positive integer.\n");
        return 1;
    }
    if (n < 0) {
        printf("Input must be positive.\n");
        return 1;
    }
    if (input[strlen(input)-1] != '\n') {
        printf("Input too long.\n");
        return 1;
    }
    for (i = 0; input[i] != '\n'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            printf("Invalid input format. Please enter a positive integer.\n");
            return 1;
        }
    }

    fprintf(fp, "\nProgram Purpose: Create a circular linked list \
                 \nrepresenting the Fibonacci series of a given length n,\
                 \nsort the list in descending order, and print it to the \
                 \nconsole and write it to a file.\
                 \nThe value of n given is: %u\n", n);

    /* Generate Fibonacci series using a circular linked list */
    fibonacci_calc(&head, n);

    if (n > 0) {
        printf("List in descending order: ");
        printLinkedList(head, NULL); /* Print to console */
    }
    else
        printf("List in descending order: 1\n");
    
    printf("\n");
    if (n > 0) {
        fprintf(fp, "\n\nFibonacci series of length %u in descending order:\n", n);
        printLinkedList(head, fp);  /* Write to file */
        printf("\n");
        fprintf(fp, "\n");
    }
    else
        fprintf(fp, "\nFibonacci series of length 0 in descending order:\n1\n");

    fclose(fp);

    return 0;
}
