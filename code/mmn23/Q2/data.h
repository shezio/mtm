typedef struct node {
    char *fibostr;  /* define a pointer to a string variable to store the Fibonacci number */
    struct node *next;
    struct node *prev;
} Node;

int compareStrings(const void* a, const void* b);
void radix_sort(Node **head);
void printLinkedList(Node *head, FILE* fp);
void fibonacci_calc(Node **head, int n);
void insert_node(Node **head, char* data);
Node *create_node(char* data);
