#include "complex.h"

#define VARIABLE_COUNT 6

/* The maximum length of an input line */
#define MAX_LINE_LENGTH 200

/* The maximum number of parameters a command can have */
#define MAX_PARAM_COUNT 3

/**
 * @brief An enumeration representing the possible types of commands that can be entered by the user.
 */
typedef enum command_type {
    ERROR, STOP, NONE, READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP,
    MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP
} command_type;

/**
 * @brief An enumeration representing boolean values.
 * It defines two values: FALSE with a value of 0 and TRUE with a value of 1.
 */
typedef enum booleans { FALSE = 0, TRUE } boolean;

/**
 * @brief Parses a user command string into a command type and up to 3 parameters.
 *
 * @param line The command string entered by the user.
 * @param params_out An array of strings to hold the parameters of the command.
 * @param param_count A pointer to an integer that will hold the number of parameters found in the command string.
 * @return The type of command entered by the user, or ERROR if the command was not recognized.
 */
command_type get_command(char line[], char *params_out[3], int *param_count);

/**
 * @brief Determines the type of a command based on its name.
 *
 * @param command The name of the command.
 * @return The type of the command, or NONE if the command was not recognized.
 */
command_type check_command_string(char command[]);

/**
 * @brief Checks whether the number of parameters provided for a command is correct.
 *
 * @param expected_param_count The expected number of parameters for the command.
 * @param actual_param_count The actual number of parameters provided by the user.
 * @return TRUE if the number of parameters is correct, FALSE otherwise.
 */
boolean check_param_number(int expected_param_count, int actual_param_count);

/**
 * @brief Returns a pointer to the complex variable (A-F) with the given name.
 *
 * @param name The name of the variable.
 * @return A pointer to the complex variable, or NULL if no variable with that name exists.
 */
complex *get_variable_by_name(char *name);

/* An array to hold the complex variables */
complex *complexes[VARIABLE_COUNT];
