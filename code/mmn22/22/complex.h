
typedef struct complex {
    double real, imaginary;
} complex;

complex* empty_comp();

void read_comp(complex*, double, double);

void print_comp(complex*);

void add_comp(complex *, complex*);

void sub_comp(complex *, complex*);

void mult_comp_real(complex *, double);

void mult_comp_img(complex *, double);

void mult_comp_comp(complex *, complex*);

double abs_comp(complex *);
