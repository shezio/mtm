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
    /* Initialize variables */
    unsigned int n, i, j;
    struct node *head = NULL;    /* Pointer to the beginning of the list */
    struct node *curr = NULL;    /* Pointer to the current node of the list */
    struct node *current = NULL; /* Pointer to the temporary node of the list */
    unsigned long long int *arr; /* Pointer to an array of Fibonacci series numbers */
    unsigned long long int temp; /* Temporary variable used for sorting */
    char input[256];             /* Input string for reading user input */
    
    /* Check if file name was given */
    if (argc != 2) {
        printf("Missing file name.\n");
        return 1;
    }
    /* Attempt to open the file */
    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("File couldn't be opened.\n");
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
    if (n < 1) {
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

    fprintf(fp, "\nProgram Purpose: Create a circular linked list");
    fprintf(fp, "\nrepresenting the Fibonacci series of a given length n,");
    fprintf(fp, "\nsort the list in descending order, and print it to the console and write it to a file.\n");
    fprintf(fp, "The value of n given is: %u\n", n);

    /* Generate Fibonacci series using a circular linked list */
    addNode(&head, 0);
    addNode(&head, 1);

    /* Sort the Fibonacci series in descending order using an array */
    for (i = 2; i <= n; i++) {
        addNode(&head, head->data + head->next->data);
    }

    printf("List in descending order: ");
    curr = head;
    *arr = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

     /* Print the sorted Fibonacci series to the console and write it to a file */
    for (i = 0; i < n; i++) {
        printf("%llu ", arr[i]);
        fprintf(fp, "%llu ", arr[i]);
    }
    printf("\n");
    fprintf(fp, "\n\nFibonacci series of length %u in descending order.\n", n);
    
    /* Traverse the circular linked list starting from head node
    and print each node's data to console and write to file */
    current = head;
    do {
        printf("%llu ", current->data);
        fprintf(fp, "%llu ", current->data);
        current = current->next;
    } while (current != head);

    /* Free dynamically allocated memory for the array and the linked list */
    free(arr);
    freeList(&head);

    /* Close the file and return 0 to indicate successful execution */
    fclose(fp);
    return 0;
}
