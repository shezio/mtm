/**
 * This program takes a positive integer as input and prints its binary
 * representation, along with the count of even-indexed 1 bits in the binary
 * representation.
 */

#include <stdio.h>

/**
 * This function counts the number of even-indexed 1 bits in the binary
 * representation of a given unsigned long integer.
 *
 * @param n the unsigned long integer to count the bits for
 * @return the number of even-indexed 1 bits in the binary representation of n
 */
unsigned int count_bits(unsigned long n) {
    /* Initialize the counter to zero */
    int count = 0;
    int i;

    /* Iterate through each bit of the integer */
    for (i = 0; n > 0; i++) {
        /* If the bit is 1 and its index is even, increment the counter */
        if ((n & 1) && (i % 2 == 0)) {
            count++;
        }
        /* Shift the integer to the right by one bit */
        n >>= 1;
    }

    /* Return the final count of even-indexed 1 bits */
    return count;
}

/**
 * This is the main function that reads a positive integer from the user,
 * prints its binary representation, and counts the even-indexed 1 bits.
 */
int main() {
    /* Declare variables to hold the input and output values */
    unsigned int decimal_input;
    unsigned long binary_output = 0;
    unsigned long power = 1;
    int i, found_nonzero = 0;

    /* Prompt the user to enter a positive integer */
    printf("Enter a positive integer: ");
    scanf("%u", &decimal_input);

    /* Convert the decimal input to binary and print it */
    printf("\nThis is the decimal input: %u", decimal_input);
    while (decimal_input > 0) {
        binary_output += (decimal_input % 2) * power;
        power <<= 1;
        decimal_input >>= 1;
    }
    printf("\nBinary output: ");
    for (i = 31; i >= 0; i--) {
        if ((binary_output >> i) & 1) {
            found_nonzero = 1;
        }
        if (found_nonzero) {
            printf("%c", (binary_output >> i) & 1 ? '1' : '0');
        }
    }
    if (!found_nonzero) {
        printf("0");
    }

    /* Count the even-indexed 1 bits in the binary representation and print the result */
    printf("\nCount of even-indexed 1 bits: %u\n", count_bits(binary_output));

    /* Return 0 to indicate successful completion of the program */
    return 0;
}
