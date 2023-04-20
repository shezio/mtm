#include "complex.h"
#define VARIABLE_COUNT 6


#define MAX_LINE_LENGTH 200
#define MAX_param_COUNT 3

typedef enum command_type {
    ERROR, STOP, NONE , READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP,
    MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP
} command_type;

command_type get_command(char [], char *[3], int *);

command_type check_command_string(char[]);

typedef enum booleans { FALSE = 0, TRUE } boolean;

boolean check_param_number(int expected_param_count, int actual_param_count);

complex *get_variable_by_name(char *name);

complex *complexes[VARIABLE_COUNT];