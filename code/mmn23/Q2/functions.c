#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/**
 * Prints the data stored in each node of a linked list starting from the given head node.
 *
 * @param head A pointer to the head node of the linked list.
 */
void printList(struct node *head) {
    struct node *curr = NULL;      /* Pointer to the current node of the list */
    
    /* If the linked list is empty, print a message and return */
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    /* Traverse the linked list and print the data in each node */
    curr = head;
    do {
        printf("%lu ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}


/**
 * Adds a new node with the given value to the beginning of the circular linked list.
 *
 * @param head A pointer to a pointer to the head node of the linked list.
 * @param val  The value to be added to the linked list.
 */
void addNode(struct node **head, unsigned long int val) {
    struct node *last = NULL;
    /* Allocate memory for the new node */
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;

    /* If the linked list is empty, make the new node the head */
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        /* Traverse the linked list to find the last node */
        last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        /* Add the new node to the end of the linked list */
        last->next = newNode;
        *head = newNode;
    }

    printf("Address of head: %p\n", (void *)head);
    printf("Address of newNode->next: %p\n", (void *)&newNode->next);
    printf("Address of *head: %p\n", (void *)*head);
    printf("Address of newNode: %p\n", (void *)newNode);
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