/**
 * This program demonstrates the usage of string manipulation functions
 * implemented in the `my_string` module. It prompts the user to enter
 * input for each of the string functions, and prints the result to the
 * console.
 *
 * Usage:
 *    - To compare two strings using `my_strcmp`, enter two strings when prompted.
 *    - To compare the first N characters of two strings using `my_strncmp`, enter
 *      two strings and the number of characters to compare.
 *    - To find the location of a character in a string using `my_strchr`, enter a
 *      string and a character to search for.
 *
 * Inputs:
 *    - String
 *    - Int
 *    - Char
 *
 * Returns:
 *    - An integer indicating the exit status of the program.
 */

#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main() {
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
    int num_of_chars_to_compare;
    char char_to_search_for_index;
    
    /* If the first char is a newline - then we are using the keyboard */
        printf("Hi! Insert 2 strings to compare using my_strcmp function");
        printf("\n Insert 2 strings and a number to compare first N chars using my_strncmp function");
        printf("\n Insert a string and a char to find its location in the string using my_strchr function");

        /* Calling my_strcmp */
        printf("\n Calling my_strcmp");
        printf("\n Please insert 2 strings, each with max size of %d characters: ", MAX_SIZE-1);
        printf("\nInput the first string: ");
        scanf("%s",str1);
        printf("\nInput the second string: ");
        scanf("%s",str2);
        printf("\nThe result is: %d\n",my_strcmp(str1, str2));
        /* Calling my_strncmp */
        printf("\n Calling my_strncmp");
        printf("\nPlease insert 2 strings, each with max size of \n max %d characters and a number not greater than max %d characters:", MAX_SIZE-1, MAX_SIZE-1);
        printf("\nInput the first string: ");
        scanf("%s",str1);
        printf("\nInput the second string: ");
        scanf("%s",str2);
        printf("\nInput the number of characters to compare: ");
        scanf("%d",&num_of_chars_to_compare);
        printf("\nThe result is: %d\n",my_strncmp(str1, str2,num_of_chars_to_compare));
        /* Calling my_strchr */
        printf("\n Calling my_strchr");
        printf("\nType string to the str: ");
        scanf("%s",str1);
        printf("Type char to get index of: ");
        scanf(" %c", &char_to_search_for_index);
        printf("\nThe result is: %d\n",my_strchr(str1, char_to_search_for_index));
    return 0;
}

