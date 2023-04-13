/*
 * C program to create a circular linked list representing the Fibonacci series of a given length n,
 * sort the list in descending order, and print it to the console and write it to a file.
 *
 * The program accepts a file name as a command line argument, and interactively gets an unsigned integer n from the user.
 * It checks for error conditions such as invalid argument amount, file couldn't be opened, memory allocation failed, and negative input.
 *
 * The program creates a circular linked list to store the Fibonacci series, sorts the list in descending order,
 * and prints it to the console and writes it to the given file with a headline that describes the program purpose and the number n.
 *
 * The program frees the memory used by the linked list and closes the file before exiting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int main(int argc, char *argv[]) {
    unsigned int n, i;          /* Initialize index variables and Fibo series length variable*/
    struct node *head = NULL;      /* Pointer to the beginning of the list */
    char input[256];               /* Input string for reading user input */
    FILE *fp;                      /* File pointer to write to output file */
    
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
    printf("Please enter a positive integer: ");
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
    addNode(&head, 0);
    addNode(&head, 1);

    /* Sort the Fibonacci series in descending order using an array */
    for (i = 2; i < n; i++) {
        addNode(&head, head->data + head->next->data);
    }

    if (n > 0) {
        addNode(&head, 0); /* add a node with data 0 to the end */
        printf("List in descending order: ");
        printList(head, n, NULL); /* Print to console */
    }
    else
        printf("List in descending order: 0\n");
    
    printf("\n");
    if (n > 0) {
        fprintf(fp, "\n\nFibonacci series of length %u in descending order:\n", n);
        printList(head, n, fp); /* Write to file */
        printf("\n");
        fprintf(fp, "\n");
    }
    else
        fprintf(fp, "\nFibonacci series of length 0 in descending order:\n0\n");

    /* Free dynamically allocated memory for the array and the linked list */
    fclose(fp);
    freeList(&head);

    return 0;
}
