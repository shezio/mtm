/**
 * struct node - Represents a node in the circular linked list.
 *
 * @data: the unsigned long int value stored in the node.
 * @next: a pointer to the next node in the circular linked list.
 */
struct node {
    long long int data;
    struct node *next;
    struct node *prev;
};

void printLinkedList(struct node *head, FILE* fp);
void addNode(struct node **head, long long int val);
void freeList(struct node **head);
