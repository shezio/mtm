/**
 * @brief A struct representing a complex number.
 * 
 * @param real The real part of the complex number.
 * @param imaginary The imaginary part of the complex number.
 */
typedef struct complex {
    double real, imaginary;
} complex;

/**
 * @brief Creates a new empty complex number.
 * 
 * @return A pointer to the new complex number.
 */
complex* empty_comp();

/**
 * @brief Reads the real and imaginary parts of a complex number.
 * 
 * @param c A pointer to the complex number to read into.
 * @param real The real part to set.
 * @param img The imaginary part to set.
 */
void read_comp(complex *c, double real, double img);

/**
 * @brief Prints the real and imaginary parts of a complex number.
 * 
 * @param c A pointer to the complex number to print.
 */
void print_comp(complex* c);

/**
 * @brief Adds two complex numbers.
 * 
 * @param c1 A pointer to the first complex number to add.
 * @param c2 A pointer to the second complex number to add.
 */
void add_comp(complex* c1, complex* c2);

/**
 * @brief Subtracts two complex numbers.
 * 
 * @param c1 A pointer to the first complex number to subtract.
 * @param c2 A pointer to the second complex number to subtract.
 */
void sub_comp(complex* c1, complex* c2);

/**
 * @brief Multiplies a complex number by a real number.
 * 
 * @param c A pointer to the complex number to multiply.
 * @param real The real value to multiply the complex number by.
 */
void mult_comp_real(complex* c, double real);

/**
 * @brief Multiplies a complex number by an imaginary number.
 * 
 * @param c A pointer to the complex number to multiply.
 * @param img The imaginary value to multiply the complex number by.
 */
void mult_comp_img(complex* c, double img);

/**
 * @brief Multiplies two complex numbers.
 * 
 * @param c1 A pointer to the first complex number to multiply.
 * @param c2 A pointer to the second complex number to multiply.
 */
void mult_comp_comp(complex* c1, complex* c2);

/**
 * @brief Calculates the absolute value of a complex number.
 * 
 * @param c A pointer to the complex number to calculate the absolute value of.
 * @return The absolute value of the complex number.
 */
double abs_comp(complex* c);
