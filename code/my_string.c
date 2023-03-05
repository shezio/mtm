#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>

#define MAX_SIZE 81

int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, int n);
int my_strchr(const char *str, int c);

int main(int argc, char *argv[]) {
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
    int n;
    char c;

    // Check if a file is specified or input is from stdin
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
        // no input redirection, use scanf
	    printf("\n Please enter input appropriate to get the result u seek:");
        printf("\n To compare length of 2 strings pls insert 2 strings with max size of:(max %d characters): ", MAX_SIZE-1);
        printf("\n To compare the first n chars of 2 strings pls insert 2 strings with max size of (max %d characters) and an a number smaller or equal to (max %d characters):", MAX_SIZE-1, MAX_SIZE-1);
        printf("\n To find the index of a character that exists in a string pls provide a string with max size of (max %d characters)  and a char u wish to find:",MAX_SIZE-1);
        if (scanf("%s", str1) != 1) {
            printf("Error reading input\n");
            return 1;
        }
	    printf("\nEnter string 2 (max %d characters): ", MAX_SIZE-1);
        if (scanf("%s", str2) != 1) {
            printf("Error reading input\n");
            return 1;
        }
    } else {
        // input redirection, use fgets
        if (fgets(str1, MAX_SIZE, stdin) == NULL) {
            printf("Error reading input\n");
            return 1;
        }
        if (fgets(str2, MAX_SIZE, stdin) == NULL) {
            printf("Error reading input\n");
            return 1;
        }
    
    }

    // Determine which function to use based on input
    int num_inputs = fscanf(fp, "%s %s %d %c", str1, str2, &n, &c);
    if (num_inputs == 2) {
        printf("Using my_strcmp.\n");
        int result = my_strcmp(str1, str2);
        printf("Result: %d\n", result);
    } else if (num_inputs == 3) {
        printf("Using my_strncmp.\n");
        int result = my_strncmp(str1, str2, n);
        printf("Result: %d\n", result);
    } else if (num_inputs == 4) {
        printf("Using my_strchr.\n");
        int result = my_strchr(str1, c);
        if (result == -1) {
            printf("Character not found.\n");
        } else {
            printf("Result: %d\n", result);
        }
    } else {
        printf("Invalid input.\n");
    }

    // Close file if necessary
    if (argc == 2) {
        fclose(fp);
    }

	return 0;
}
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return (*(unsigned char*)str1 < *(unsigned char*)str2) ? -1 : 1;
}
int my_strncmp(const char *str1, const char *str2, int n) {
    if (n == 0)
        return 0;
    while (n-- != 0) {
        if (*str1 != *str2)
            return (*(unsigned char*)str1 - *(unsigned char*)str2);
        if (n == 0 || *str1 == '\0' || *str2 == '\0')
            break;
        str1++;
        str2++;
    }
    return 0;
}
int my_strchr(const char *str, int c) {
    int index = 0;
    while (*str != '\0') {
        if (*str == (char)c) {
            return index;
        }
        str++;
        index++;
    }
    return -1;
}
