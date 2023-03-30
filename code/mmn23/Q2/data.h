/**
 * struct node - Represents a node in the circular linked list.
 *
 * @data: the unsigned long int value stored in the node.
 * @next: a pointer to the next node in the circular linked list.
 */
struct node {
    unsigned long int data;
    struct node *next;
};

void printList(struct node *head);
void addNode(struct node **head, unsigned long int val);
void freeList(struct node **head);