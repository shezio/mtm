#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

/**
 * This function is used as a comparison function for qsort() to sort an array of string pointers
 * in descending order, as if they were big integers.
 *
 * @param a a pointer to a pointer of a string
 * @param b a pointer to a pointer of a string
 * @return 1 if a should come before b in the sorted order, -1 if b should come before a, or 0 if they are equal
 */
int compareStrings(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i;

    /* Pad the shorter string with leading zeros */
    if (len1 < len2) {
        char *new_str1 = (char *)malloc((len2 + 1) * sizeof(char));
        sprintf(new_str1, "%0*d%s", len2 - len1, 0, str1);
        str1 = new_str1;
        len1 = len2;
    } else if (len1 > len2) {
        char *new_str2 = (char *)malloc((len1 + 1) * sizeof(char));
        sprintf(new_str2, "%0*d%s", len1 - len2, 0, str2);
        str2 = new_str2;
        len2 = len1;
    }

    /* Compare the strings */
    for (i = 0; i < len1; i++) {
        if (str1[i] < str2[i]) {
            return 1;
        } else if (str1[i] > str2[i]) {
            return -1;
        }
    }

    /* Free the temporary strings */
    if (len1 < len2) {
        free((char *)str1);
    } else if (len1 > len2) {
        free((char *)str2);
    }

    return 0;
}

/**
 * Prints the data stored in each node of a linked list starting from the given head node.
 *
 * @param head      A pointer to the head node of the linked list.
 * @param fp        A file pointer, NULL on print to console 
 */
void printLinkedList(Node *head, FILE* fp) {
    Node *temp = head;
    char** arr = NULL;
    int i,count = 0;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    /* Count the number of nodes in the linked list */
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    count++; /* Count the last node */
    
    /* Put the values of the linked list into an array */
    arr = (char**)malloc(sizeof(char*) * count);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp = head;
    for (i = 0; i < count; i++) {
        arr[i] = temp->fibostr;
        temp = temp->next;
    }
    
    /* Sort the array in descending order using string comparison function */
    qsort(arr, count, sizeof(char*), compareStrings);
    
    /* Write the sorted array to a file */
    if (fp != NULL) {
        for (i = 0; i < count; i++) {
            fprintf(fp, "%s ", arr[i]);
        }
    }
    /* Print the sorted array */
    else {
        for (i = 0; i < count; i++) {
            printf("%s ", arr[i]);
        }
    }
    printf("\n");

    free(arr);
}

/**
 * Creates a new node for a linked list with the given data.
 *
 * @param data      The data to be stored in the new node.
 * @return          A pointer to the newly created node.
 */
Node *create_node(char* data) {
    /* Allocate memory for the new node */
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    /* Allocate memory for the string and copy the data into the new node */
    new_node->fibostr = (char *)malloc((strlen(data) + 1) * sizeof(char));
    strcpy(new_node->fibostr, data);
    
    /* Set the next pointer to NULL */
    new_node->next = NULL;
    
    /* Return a pointer to the newly created node */
    return new_node;
}

/**
 * Inserts a new node containing the given string data into the circular linked list.
 * 
 * @param head      A pointer to a pointer to the head node of the linked list.
 * @param data      The string data to be stored in the new node.
 */
void insert_node(Node **head, char* data) {
    Node *new_node = create_node(data);  /* create a new node */
    if (*head == NULL) {  /* if the list is empty, set the new node as the head node */
        *head = new_node;
        new_node->next = *head;
    }
    else {  /* otherwise, traverse the list to find the last node, and append the new node to it */
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
    }
}

/**
 * Calculates and inserts the first n numbers of the Fibonacci sequence
 * into a linked list starting at the head.
 * Disclaimer: The usual Fibonacci starts with 0 as the 1st value.
 * The requirement here was to start from 1.
 * @param head A pointer to the head node of the linked list.
 * @param n The number of Fibonacci numbers to calculate and insert.
 */
void fibonacci_calc(Node **head, int n) {
    char *fibostr1 = "1";
    char *fibostr2 = "1";
    char *fibostr = NULL;
    char *new_fibostr = NULL;
    int i, j, k, sum, carry = 0;

    /* If n is 0, insert "1" into the list and return. */
    if (n == 0) {
        insert_node(head, "1");
        return;
    }

    /* If n is 1, insert "1" twice into the list and return. */
    if (n == 1) {
        insert_node(head, "1");
        insert_node(head, "1");
        return;
    }

    /* Insert "1" and "1" into the list to start the sequence. */
    insert_node(head, "1");
    insert_node(head, "1");

    /* Calculate and insert the remaining Fibonacci numbers into the list. */
    for (i = 2; i < n; i++) {
        fibostr = (char *) calloc(strlen(fibostr2) + 1, sizeof(char));
        j = strlen(fibostr1) - 1;
        k = strlen(fibostr2) - 1;

        /* Add the two previous numbers with any carry over. */
        for (; j >= 0; j--, k--) {
            sum = (fibostr1[j] - '0') + (fibostr2[k] - '0') + carry;
            fibostr[k] = (sum % 10) + '0';
            carry = sum / 10;
        }

        /* Add any carry over from the previous loop to the remaining digits. */
        for (; k >= 0; k--) {
            sum = (fibostr2[k] - '0') + carry;
            fibostr[k] = (sum % 10) + '0';
            carry = sum / 10;
        }

        /* If there is still a carry over, add it to the beginning of the string. */
        if (carry) {
            new_fibostr = (char *) malloc((strlen(fibostr) + 2) * sizeof(char));
            sprintf(new_fibostr, "1%s", fibostr);
            fibostr = new_fibostr;
        }

        /* Insert the calculated Fibonacci number into the list. */
        insert_node(head, fibostr);

        /* Move the pointers to the two previous Fibonacci numbers. */
        fibostr1 = fibostr2;
        fibostr2 = fibostr;

        /* Reset the carry over. */
        carry = 0;
    }

    /* Free the memory allocated for the last Fibonacci number. */
    free(fibostr);
}
