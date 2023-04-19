#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

#include <stdlib.h>
#include <string.h>

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

/* void radix_sort(Node **head) {
    int count = 0, max_len = 0, i, j, k, len;
    char **arr = NULL;
    Node *temp = *head;

    
    while (temp->next != *head) {
        count++;
        len = strlen(temp->fibostr);
        if (len > max_len) {
            max_len = len;
        }
        temp = temp->next;
    }
    count++;
    len = strlen(temp->fibostr);
    if (len > max_len) {
        max_len = len;
    }

    arr = (char **)malloc(sizeof(char *) * count);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp = *head;
    for (i = 0; i < count; i++) {
        arr[i] = temp->fibostr;
        temp = temp->next;
    }

    for (i = max_len - 1; i >= 0; i--) {
        int freq[10] = {0};
        char **temp_arr = (char **)malloc(sizeof(char *) * count);
        if (temp_arr == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        for (j = 0; j < count; j++) {
            int index = arr[j][i] - '0';
            freq[index]++;
        }
        for (j = 1; j < 10; j++) {
            freq[j] += freq[j - 1];
        }
        for (j = count - 1; j >= 0; j--) {
            int index = arr[j][i] - '0';
            temp_arr[freq[index] - 1] = arr[j];
            freq[index]--;
        }
        for (j = 0; j < count; j++) {
            arr[j] = temp_arr[j];
        }
        free(temp_arr);
    }

    temp = *head;
    for (i = 0; i < count; i++) {
        strcpy(temp->fibostr, arr[i]);
        temp = temp->next;
    }

    free(arr);
} */


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


Node *create_node(char* data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->fibostr = (char *)malloc((strlen(data) + 1) * sizeof(char)); /* allocate memory for the string */
    strcpy(new_node->fibostr, data);
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head, char* data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        new_node->next = *head;
    }
    else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
    }
}

void fibonacci_calc(Node **head, int n) {
    char *fibostr1 = "1";
    char *fibostr2 = "1";
    char *fibostr = NULL;
    char *new_fibostr = NULL;
    int i, j, k, sum, carry = 0;

    if (n == 0) {
        insert_node(head, "1");
        return;
    }

    if (n == 1) {
        insert_node(head, "1");
        insert_node(head, "1");
        return;
    }

    insert_node(head, "1");
    insert_node(head, "1");

    for (i = 2; i < n; i++) {
        fibostr = (char *) calloc(strlen(fibostr2) + 1, sizeof(char));
        j = strlen(fibostr1) - 1;
        k = strlen(fibostr2) - 1;

        for (; j >= 0; j--, k--) {
            sum = (fibostr1[j] - '0') + (fibostr2[k] - '0') + carry;
            fibostr[k] = (sum % 10) + '0';
            carry = sum / 10;
        }
        for (; k >= 0; k--) {
            sum = (fibostr2[k] - '0') + carry;
            fibostr[k] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry) {
            new_fibostr = (char *) malloc((strlen(fibostr) + 2) * sizeof(char));
            sprintf(new_fibostr, "1%s", fibostr);
            fibostr = new_fibostr;
        }
        insert_node(head, fibostr);
        fibostr1 = fibostr2;
        fibostr2 = fibostr;
        carry = 0;
    }
    free(fibostr);
}
