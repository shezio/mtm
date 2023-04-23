#include <stdio.h>
#include <string.h>
#include "mycomp.h"

/**
 * Parses a user command string into a command type and up to 3 parameters.
 *
 * @param line The command string entered by the user.
 * @param params_out An array of strings to hold the parameters of the command.
 * @param param_count A pointer to an integer that will hold the number of parameters found in the command string.
 * @return The type of command entered by the user, or ERROR if the command was not recognized.
 */
command_name get_command(char line[], char *params_out[MAX_PARAM_COUNT], int *param_count)
{
	command_name to_return;
	char *command, *rest;
	char line_copy[MAX_LINE_LENGTH];
	int total_line_length = strlen(line);
	/* Get the command from the line */
	command = strtok(line, "\t \n");

	if (command == NULL)
		return NONE;

	/* Check if the command is a valid command */
	to_return = check_command_string(command);
	if (to_return == ERROR || to_return == STOP || strlen(command) == total_line_length - 1)
		return to_return;

	/* Copy the line to a separate buffer */
	memcpy(line_copy, line, total_line_length);
	rest = command + strlen(command) + 1;

	/* Check for illegal commas */
	if (*strtok(command + strlen(command) + 1, "\t ") == ',')
	{
		puts("Illegal comma");
		return ERROR;
	}

	/* Copy the line back */
	memcpy(line, line_copy, total_line_length);

	/* Extract parameters */
	for (*param_count = 0; *param_count < MAX_PARAM_COUNT && strlen(rest) > 0;)
	{
		char *first, *second, *curr_part;

		/* Get the current parameter */
		curr_part = strtok(rest, ",");
		rest = curr_part + strlen(curr_part) + 1;

		/* Get the first part of the parameter (up to the first whitespace) */
		first = strtok(curr_part, "\t ");

		/* Check for error */
		if (first == NULL || (rest < line + total_line_length && *rest == ','))
		{
			puts("Multiple consecutive commas");
			return ERROR;
		}
		else if (*first == '\n')
			break;

		/* Get the second part of the parameter (if exists) */
		second = strtok(NULL, "\t ");

		/* Check for errors */
		if (second != NULL && *second != '\n')
		{
			puts("Missing comma");
			return ERROR;
		}

		/* Remove trailing newline from first part of parameter */
		if (*(first + strlen(first) - 1) == '\n')
			first[strlen(first) - 1] = '\0';

		/* Store parameter in params_out */
		params_out[(*param_count)++] = first;

		/* Check if we've reached the end of the line */
		if (rest > line + total_line_length || *rest == '\n')
			break;
	}

	/* Check for extraneous text after end of command */
	if ((rest != NULL && strlen(rest) != 0 && rest < line + total_line_length))
	{
		puts("Extraneous text after end of command");
		return ERROR;
	}

	return to_return;
}

/**
 * Determines the name of a command.
 *
 * @param command The name of the command.
 * @return The name of the command, or NONE if the command was not recognized.
 */
command_name check_command_string(char command[])
{
	if (strcmp(command, "read_comp") == 0)
		return READ_COMP; /* command to read a complex number */
	else if (strcmp(command, "print_comp") == 0)
		return PRINT_COMP; /* command to print a complex number */
	else if (strcmp(command, "add_comp") == 0)
		return ADD_COMP; /* command to add two complex numbers */
	else if (strcmp(command, "sub_comp") == 0)
		return SUB_COMP; /* command to subtract two complex numbers */
	else if (strcmp(command, "mult_comp_real") == 0)
		return MULT_COMP_REAL; /* command to multiply a complex number by a real number */
	else if (strcmp(command, "mult_comp_img") == 0)
		return MULT_COMP_IMG; /* command to multiply a complex number by an imaginary number */
	else if (strcmp(command, "mult_comp_comp") == 0)
		return MULT_COMP_COMP; /* command to multiply two complex numbers */
	else if (strcmp(command, "abs_comp") == 0)
		return ABS_COMP; /* command to calculate the absolute value of a complex number */
	else if (strcmp(command, "stop") == 0)
		return STOP; /* command to stop the program */
	else
	{
		puts("Undefined command name");
		return ERROR; /* undefined command */
	}
}

/**
 * Returns a pointer to the complex variable (A-F) with the given name.
 *
 * @param name The name of the variable.
 * @return A pointer to the complex variable, or NULL if no variable with that name exists.
 */
complex *get_variable_by_name(complex* complexes[],char *name)
{	
	/* Check if the name is a single capital letter from A to A + VARIABLE_COUNT. */
	if (strlen(name) == 1 && name[0] >= 'A' && name[0] <= ('A' + VARIABLE_COUNT))
	{
		/* Return the corresponding complex variable. */
		return complexes[name[0] - 'A'];
	}
	/* If the name is invalid, print an error message and return NULL. */
	puts("Undefined complex variable");
	return NULL;
}

/**
 * Checks whether the number of parameters provided for a command is correct.
 *
 * @param expected_param_count The expected number of parameters for the command.
 * @param actual_param_count The actual number of parameters provided by the user.
 * @return TRUE if the number of parameters is correct, FALSE otherwise.
 */
boolean check_param_number(int expected_param_count, int actual_param_count)
{
	if (expected_param_count == actual_param_count)
	{

		return TRUE;}

	else if (expected_param_count < actual_param_count)
		puts("Extraneous text after end of command.");
	else
		puts("Missing Argument");
	return FALSE;
}
