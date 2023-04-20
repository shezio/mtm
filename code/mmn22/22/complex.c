/*
 * Contains operations for complex manipulation using the structure complex defined at complex.h
 * such as, reading, printing, and creating default complex.
 * prototypes are at complex.h.
 */
#include <stdlib.h> /* For malloc & free */
#include <math.h> /* For abs */
#include <stdio.h> /* For printf */
#include "complex.h"

/* Creates a "clean" instance of a complex (represented by 0+0i) and returns a pointer to it */
complex *empty_comp()
{
    complex *new = (complex *)malloc(sizeof(complex));
    if (!new)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    /* Default value: 0.0 for both fields */
    new->imaginary = new->real = 0.0;
    return new;
}

/* Assigns the second paramument as the real part of the complex paramument, and the third as it's imaginary part. */
void read_comp(complex *c, double real, double img)
{
    /* Assignment */
    c->real = real;
    c->imaginary = img;
}

/* Prints a complex number, formatted as real+(img)i. e.g: 5.00-(3.25)i, 2.84+(7.99)i */
void print_comp(complex *toprint)
{
    /* Two-digit precision after dot for both numeric values */
    /* Print real, then evaluate the sign of imaginary part, at the end the (image coefficient)i */
    printf("%.2f", toprint->real);
    printf((toprint->imaginary >= 0 ? "+" : "-"));
    printf("(%.2f)i\n", fabs(toprint->imaginary));
}

/* Prints the sum of both complex paramuments. */
void add_comp(complex *c1, complex *c2)
{
    complex *to_print = empty_comp(); /* Temp */
    /* (a+bi)+(c+di)=(a+c)+(b+d)i */
    to_print->imaginary = (c1->imaginary)+(c2->imaginary);
    to_print->real = (c1->real)+(c2->real);
    print_comp(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the subtraction result of the second paramument from the first. */
void sub_comp(complex *c1, complex *c2)
{
    complex *to_print = empty_comp(); /* Temp */
    /* (a+bi)-(c+di)=(a-c)+(b-d)i */
    to_print->imaginary = (c1->imaginary)-(c2->imaginary);
    to_print->real = (c1->real)-(c2->real);
    print_comp(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the multiplication result of the complex paramument and the doule number. */
void mult_comp_real(complex *c, double real)
{
    complex *to_print = empty_comp(); /* Temp */
    /* s(a+bi)=sa+sbi */
    to_print->imaginary = (c->imaginary)*real;
    to_print->real = (c->real)*real;
    print_comp(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the multiplication result of the complex paramument by the double paramument*(i) */
void mult_comp_img(complex *c, double img)
{
    complex *to_print = empty_comp(); /* Temp */
    /* si(a+bi)=sai+sbi*i=-sb+sai */
    to_print->imaginary = img * (c->real);
    to_print->real = (-1) * img * (c->imaginary);
    print_comp(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the multiplication result of both complexes, passed as paramuments to the function. */
void mult_comp_comp(complex *c1, complex *c2)
{
    complex *to_print = empty_comp(); /* Temp */

    /*(a+bi)(c+di)=ac+bci+adi+bdi*i=(ac-bd)+(ad+bc)i*/
    to_print->imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    to_print->real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);

    print_comp(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the absolute value of the first complex, given as paramument. */
double abs_comp(complex *c)
{
	/* formula: sqrt(real^2+img^2) */
    return sqrt(pow(c->real, 2)+pow(c->imaginary, 2));
}
