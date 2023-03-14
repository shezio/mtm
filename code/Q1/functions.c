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

