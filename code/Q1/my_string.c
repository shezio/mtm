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
 *    - An integer indicating the result of each function status of the program.
 */

#include <stdio.h>
#include <stdlib.h>
/* Constant for max size of the input string */
#define MAX_SIZE 81

/**
 * Compare two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return 0 if the strings are equal, a positive value if s1 is greater than s2, and a negative value if s1 is less than s2.
 */
int my_strcmp(char[], char[]);
/**
 * Compares the first n characters of two strings lexicographically.
 * Returns an integer greater than, equal to, or less than zero,
 * depending on whether str1 is greater than, equal to, or less than str2.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * 
 * @return  An integer greater than, equal to, or less than zero,
 *          depending on whether str1 is greater than, equal to, or less than str2.
 */
int my_strncmp(char[], char[],int);
/*
 * The `my_strchr()` function searches the string pointed to by `s`
 * for the first occurrence of the character `c`.
 *
 * @param s: A pointer to the string to be searched.
 * @param c: The character to be located.
 *
 * @return: The index of the first occurrence of `c` in `s`, or -1 if `c`
 *          is not found in `s`.
 */
int my_strchr(char[], char);
int main(int argc, char *argv[]) {
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
    int num_of_chars_to_compare;
    char char_to_search_for_index;
    
    if (argc == 2) { /* if the file is specified in the command line argument */
        freopen(argv[1], "r", stdin); /*  redirect standard input to the file */
    }
    /* If the first char is a newline - then we are using the keyboard */
    printf("Hi! Insert 2 strings to compare using my_strcmp function");
    printf("\n Insert 2 strings and a number to compare first N chars using my_strncmp function");
    printf("\n Insert a string and a char to find its location in the string using my_strchr function");

    /* Calling my_strcmp */
    printf("\n Calling my_strcmp");
    printf("\n Please insert 2 strings, each with max size of %d characters: ", MAX_SIZE-1);
    printf("\nInput the first string: ");
    scanf("%s", str1);
    printf("\nInput the second string: ");
    scanf("%s", str2);
    printf("\nThe result is: %d\n",my_strcmp(str1, str2));
    /* Calling my_strncmp */
    printf("\n Calling my_strncmp");
    printf("\nPlease insert 2 strings, each with max size of \n max %d characters and a number not greater than max %d characters:", MAX_SIZE-1, MAX_SIZE-1);
    printf("\nInput the first string: ");
    scanf("%s", str1);
    printf("\nInput the second string: ");
    scanf("%s", str2);
    printf("\nInput the number of characters to compare: ");
    scanf("%d",&num_of_chars_to_compare);
    printf("\nThe result is: %d\n",my_strncmp(str1, str2,num_of_chars_to_compare));
    /* Calling my_strchr */
    printf("\n Calling my_strchr");
    printf("\nType string to the str: ");
    scanf("%s", str1);
    printf("Type char to get index of: ");
    scanf(" %c", &char_to_search_for_index);
    printf("\nThe result is: %d\n",my_strchr(str1, char_to_search_for_index));
    return 0;
}

/**
 * Compare two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return 0 if the strings are equal, a positive value if s1 is greater than s2, and a negative value if s1 is less than s2.
 */
int my_strcmp(char s1[], char s2[]) {
    int i = 0;

    /*  Iterate through the strings until a difference is found or until the end of the string is reached */
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') { /*  If the end of the string is reached and there is no difference, the strings are equal */
            return 0;
        }
        i++;
    }

    /*  If a difference is found, return the difference between the ASCII values of the characters */
    return s1[i] - s2[i];
}


/**
 * Compares the first n characters of two strings lexicographically.
 * Returns an integer greater than, equal to, or less than zero,
 * depending on whether str1 is greater than, equal to, or less than str2.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * 
 * @return  An integer greater than, equal to, or less than zero,
 *          depending on whether str1 is greater than, equal to, or less than str2.
 */
int my_strncmp(char str1[], char str2[], int n) {
    int i;

    /* Compare the first n characters of str1 and str2 */
    for (i = 0; i < n && str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
    }

    /* If the first n characters are equal, check the null terminator */
    if (i == n) {
        return 0;
    } else if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}


/*
 * The `my_strchr()` function searches the string pointed to by `s`
 * for the first occurrence of the character `c`.
 *
 * @param s: A pointer to the string to be searched.
 * @param c: The character to be located.
 *
 * @return: The index of the first occurrence of `c` in `s`, or -1 if `c`
 *          is not found in `s`.
 */
int my_strchr(char s[], char c) {
    int i = 0;
    
    /* Loop through the string until the end or until the character is found */
    while (s[i] != '\0' && s[i] != c) {
        i++;
    }
    
    /* If the character was found, return its index, otherwise return -1 */
    if (s[i] == c) {
        return i;
    } else {
        return -1;
    }
}

