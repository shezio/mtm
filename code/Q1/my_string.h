/* Constant fro max size of the input string */
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