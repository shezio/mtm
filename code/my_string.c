#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int my_strcmp(char[], char[]);
int my_strncmp(char[], char[],int);
int my_strchr(char[], char);

int main(int argc, char *argv[]) {
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
    int num_of_chars_to_compare;
    int selection = 0;
    char char_to_search_for_index;

    /* Check if a file is specified or input is from stdin */
    FILE *fp;
    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }
    } else {
        fp = stdin;
    }

	if (fp == stdin) {
        printf("\nPlease select a function:");
        printf("\n To compare length of 2 strings using my_strcmp function please select (1) ");
        printf("\n To compare the first N characters of 2 strings using my_strncmp function please select (2) ");
        printf("\n To find the location of a character in a string using my_strchr function please select (3) ");
        printf("\nInput your selection please: ");
        scanf("%d",&selection);
        switch(selection)
        {
            case 1: /*my_strcmp function:*/
                printf("\n Please insert 2 strings, each with max size of:(max %d characters): ", MAX_SIZE-1);
                printf("\nInput the first string: ");
                scanf("%s",str1);
                printf("\nInput the second string: ");
                scanf("%s",str2);
                printf("\nThe result is: %d\n",my_strcmp(str1, str2));
                break;		
            case 2: /*my_strncmp function:*/
                printf("\nPlease insert 2 strings, each with max size of (max %d characters) and a number not greater than (max %d characters):", MAX_SIZE-1, MAX_SIZE-1);
                printf("\nInput the first string: ");
                scanf("%s",str1);
                printf("\nInput the second string: ");
                scanf("%s",str2);
                printf("\nInput the number of characters to compare: ");
                scanf("%d",&num_of_chars_to_compare);
                printf("\nThe result is: %d\n",my_strncmp(str1, str2, num_of_chars_to_compare));
                break;
            case 3:	/*my_strchr function:*/
                printf("\nmy_strchr function:");
                printf("\nType string to the str: ");
                scanf("%s",str1);
                printf("Type char to get index of: ");
                scanf("%c", &char_to_search_for_index);
                printf("\nThe result is: %d\n",my_strchr(str1, char_to_search_for_index));
                break;
            default:/*non of the above function:*/
                printf("\nYour selection didn\'t feet to any of our function.\n");
                break;
	}

        if (scanf("%s", str1) != 1) {
            printf("Error reading input\n");
            return 1;
        }
        if (scanf("%s", str2) != 1) {
            printf("Error reading input\n");
            return 1;
        }
    } else {
        /*input redirection, use fgets*/ 
        if (fgets(str1, MAX_SIZE, stdin) == NULL) {
            printf("Error reading input\n");
            return 1;
        }
        if (fgets(str2, MAX_SIZE, stdin) == NULL) {
            printf("Error reading input\n");
            return 1;
        }
    
    }

    /* Close file if necessary*/
    if (argc == 2) {
        fclose(fp);
    }

    return 0;
	
}

