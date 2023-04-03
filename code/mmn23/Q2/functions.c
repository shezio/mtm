#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

/**
 * Prints the data stored in each node of a linked list starting from the given head node.
 *
 * @param head      A pointer to the head node of the linked list.
 * @param n         Fibo series length variable
 * @param fp        A file pointer, NULL on print to console 
 */
void printList(struct node *head, int n, FILE* fp) {
    struct node *curr = NULL;      /* Pointer to the current node of the list */
    unsigned long int *arr = NULL; /* Pointer to an array of Fibonacci series numbers */
    unsigned long int temp;        /* Temporary variable used for sorting */
    int i, j;
    
    curr = head;
    arr = (unsigned long int *)malloc(n * sizeof(unsigned long int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
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
    if (fp != NULL) {
        /* Write the sorted Fibonacci series to a file */
        for (i = 0; i < n; i++) {
            fprintf(fp, "%lu ", arr[i]);
        }
    }
    else {
        /* Print the sorted Fibonacci series to the console */
        for (i = 0; i < n; i++) {
            printf("%lu ", arr[i]);
        }
    }
    /* Free allocated memory for the array */
    free(arr);
}

/**
 * Adds a new node with the given value to the beginning of the circular linked list.
 *
 * @param head A pointer to a pointer to the head node of the linked list.
 * @param val  The value to be added to the linked list.
 */
void addNode(struct node **head, unsigned long int val) {
    struct node *curr = NULL;
    /* Allocate memory for the new node */
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
       printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = val;
    newNode->next = *head;

    /* If the linked list is empty, make the new node the head */
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        /* Traverse the linked list to find the last node */
        curr = *head;
        while (curr->next != *head) {
            curr = curr->next;
        }
        /* Add the new node to the end of the linked list */
        curr->next = newNode;
        *head = newNode;
    }
}
/**
 * Frees all nodes in the linked list and sets head to NULL.
 *
 * @param head - pointer to the head node of the linked list.
 */
void freeList(struct node **head) {
    struct node *curr = NULL;      /* Pointer to the current node of the list */
    struct node *temp;
    
    /* Check if the list is empty */
    if (*head == NULL) {
        return;
    }

    /* Traverse the list and free each node */
    curr = *head;
    do {
        temp = curr->next; /* Save the next node */
        free(curr); /* Free the current node */
        curr = temp; /* Move to the next node */
    } while (curr != *head); /* Stop when we reach the head again */

    *head = NULL; /* Set the head to NULL to indicate the list is empty */
}