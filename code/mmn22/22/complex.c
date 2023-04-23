#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "complex.h"

/**
 * Allocates memory for a new complex number and initializes its real
 * and imaginary parts to 0.
 *
 * @return a pointer to the newly allocated complex number
 */
complex* empty_comp()
{
    /* Allocate memory for the new complex number */
    complex *new = (complex *)malloc(sizeof(complex));
    
    /* Check if memory allocation failed */
    if (!new)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    
    /* Initialize the real and imaginary parts of the complex number to 0 */
    new->imaginary = new->real = 0.0;

    /* Return a pointer to the new complex number */
    return new;
}


/**
 * Initializes the given complex number with the provided real and
 * imaginary parts.
 *
 * @param c a pointer to the complex number to be initialized
 * @param real the real part of the complex number
 * @param img the imaginary part of the complex number
 */
void read_comp(complex *c, double real, double img)
{
    /* set the real part of the given complex number to the input real value */
    c->real = real;
    
    /* set the imaginary part of the given complex number to the input imaginary value */
    c->imaginary = img;
}

/**
 * Prints the given complex number to the console in the format:
 *    real + (|img|)i   (if img >= 0)
 * or real - (|img|)i   (if img < 0)
 *
 * @param toprint a pointer to the complex number to be printed
 */
void print_comp(complex *toprint)
{
    
    /* Print the real part rounded to two decimal places */
    printf("%.2f", toprint->real);
    
    /* Print '+' if imaginary part is non-negative, else '-' */
    printf((toprint->imaginary >= 0 ? "+" : "-"));
    
    /* Print the absolute value of the imaginary part rounded to two decimal places */
    printf("(%.2f)i\n", fabs(toprint->imaginary));
}

/**
 * Adds two complex numbers and prints the result to the console.
 *
 * @param c1 a pointer to the first complex number
 * @param c2 a pointer to the second complex number
 */
void add_comp(complex *c1, complex *c2)
{
    /* allocate memory for the resulting complex number */
    complex *to_print = empty_comp();

    /* add the imaginary parts */
    to_print->imaginary = (c1->imaginary) + (c2->imaginary);

    /* add the real parts */
    to_print->real = (c1->real) + (c2->real);

    /* print the resulting complex number */
    print_comp(to_print);

    /* free the memory allocated for the resulting complex number */
    free(to_print);
}

/**
 * Subtracts two complex numbers and prints the result to the console.
 *
 * @param c1 a pointer to the first complex number
 * @param c2 a pointer to the second complex number
 */
void sub_comp(complex *c1, complex *c2)
{
    /* create a new empty complex number */
    complex *to_print = empty_comp();

    /* subtract imaginary parts */
    to_print->imaginary = (c1->imaginary) - (c2->imaginary);

    /* subtract real parts */
    to_print->real = (c1->real) - (c2->real);

    /* print the result */
    print_comp(to_print);

    /* free the memory used by the new complex number */
    free(to_print);
}

/**
 * Multiplies a complex number by a real number and prints the result
 * to the console.
 *
 * @param c a pointer to the complex number
 * @param real the real number to multiply the complex number by
 */
void mult_comp_real(complex *c, double real)
{
    /* Creates a new complex number to print */
    complex *to_print = empty_comp();

    /* Calculates the real and imaginary components of the product */
    to_print->imaginary = (c->imaginary) * real;
    to_print->real = (c->real) * real;

    /* Prints the result */
    print_comp(to_print);

    /* Frees the memory allocated for the new complex number */
    free(to_print);
}

/**
 * Multiplies a complex number by an imaginary number and prints the
 * result to the console.
 *
 * @param c a pointer to the complex number
 * @param img the imaginary number to multiply the complex number by
 */
void mult_comp_img(complex *c, double img)
{
    /* Create a new complex number to hold the result */
    complex *to_print = empty_comp();

    /* Compute the multiplication and store the result in the new complex number */
    to_print->imaginary = img * (c->real);
    to_print->real = (-1) * img * (c->imaginary);

    /* Print the result and free the memory allocated for the new complex number */
    print_comp(to_print);
    free(to_print);
}

/**
 * Multiplies two complex numbers c1 and c2 and prints the result.
 *
 * @param c1 A pointer to the first complex number.
 * @param c2 A pointer to the second complex number.
 */
void mult_comp_comp(complex *c1, complex *c2)
{
    /* Create an empty complex number for the result */
    complex *to_print = empty_comp();

    /* Calculate the real and imaginary components of the product */
    to_print->imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    to_print->real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);

    /* Print the result and free the memory used by to_print */
    print_comp(to_print);
    free(to_print);
}

/**

Calculates the absolute value (magnitude) of a given complex number.
@param c A pointer to the complex number to calculate the absolute value of.
@return The absolute value (magnitude) of the complex number.
*/
double abs_comp(complex *c)
{
    return sqrt(pow(c->real, 2) + pow(c->imaginary, 2));
}
