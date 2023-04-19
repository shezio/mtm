/**
 * @file data.h
 *
 * @brief Header file containing declarations for functions and data types used in the Fibonacci series program.
 */

#ifndef DATA_H
#define DATA_H

/**
 * @brief A structure representing a node in a circular linked list used to store Fibonacci numbers.
 */
typedef struct node {
    char *fibostr;      /* A pointer to a string variable to store the Fibonacci number. */
    struct node *next;  /* A pointer to the next node in the list. */
    struct node *prev;  /* A pointer to the previous node in the list. */
} Node;

#define MAX_SERIES_LENGTH 10000 /* The maximum length of the Fibonacci series to be calculated. */

/**
 * @brief Compares two strings for qsort in ascending order.
 *
 * @param a The first string to be compared.
 * @param b The second string to be compared.
 *
 * @return An integer indicating the order of the strings (negative if a is less than b, 0 if they are equal, positive if a is greater than b).
 */
int compareStrings(const void* a, const void* b);

/**
 * @brief Prints the Fibonacci series stored in a linked list to a file 
 * as well as prints to the console.
 *
 * @param head A pointer to the head of the linked list.
 * @param fp A pointer to the file to which the output is written. if equals NULL, will print to console.
 */
void printLinkedList(Node *head, FILE* fp);

/**
 * @brief Calculates the first n numbers in the Fibonacci series and stores them in a linked list.
 *
 * @param head A pointer to a pointer to the head of the linked list.
 * @param n The number of Fibonacci numbers to be calculated.
 */
void fibonacci_calc(Node **head, int n);

/**
 * @brief Inserts a new node at the end of a linked list.
 *
 * @param head A pointer to a pointer to the head of the linked list.
 * @param data The string to be stored in the new node.
 */
void insert_node(Node **head, char* data);

/**
 * @brief Creates a new node with the specified string data.
 *
 * @param data The string to be stored in the new node.
 *
 * @return A pointer to the new node.
 */
Node *create_node(char* data);

#endif /* DATA_H */
