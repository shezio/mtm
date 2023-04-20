/**
 * @brief This is a program that allows the user to perform basic operations with complex numbers.
 *
 * The program takes in user input commands to create and manipulate complex numbers. The available
 * commands are: read_comp, print_comp, add_comp, sub_comp, mult_comp_real, mult_comp_img, mult_comp_comp,
 * and abs_comp.
 *
 * The program allows the user to store up to six complex numbers, which are stored in an array of complex
 * number structures.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mycomp.h"

int main()
{
	/* Initialize variables and array of complex number structures */
	char line[MAX_LINE_LENGTH], *params[3];
	int param_count, i;
	command_type command;

	for (i = 0; i < VARIABLE_COUNT; i++)
		complexes[i] = empty_comp();

	/* Prompt user for input */
	printf("Type a command and press enter to execute:\n>> ");

	/* Continuously loop through user input and execute commands until STOP command is input */
	while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
	{
		printf("%s", line);
		command = get_command(line, params, &param_count);

		switch (command)
		{
		/* Read a complex number */
		case READ_COMP:
			if (check_param_number(3, param_count))
			{
				complex *var = get_variable_by_name(params[0]);
				if (var)
				{
					char *err0 = NULL, *err1 = NULL;
					double real_val = strtod(params[1], &err0);
					double img_val = strtod(params[2], &err1);
					if (!(isspace((unsigned char)*err0) || *err0 == 0) ||
						!(isspace((unsigned char)*err1) || *err1 == 0))
					{
						puts("Invalid parameter - not a number");
						break;
					}
					read_comp(var, real_val, img_val);
				}
			}
			break;
		/* Print out a complex number or its absolute value */
		case PRINT_COMP:
		case ABS_COMP:
			if (check_param_number(1, param_count))
			{
				complex *var = get_variable_by_name(params[0]);
				if (var){
					if (command == PRINT_COMP)
						print_comp(var);
					else
						printf("%.2f", abs_comp(var));
				}
			}
			break;
		case ADD_COMP:       /* Perform addition on complex numbers */
		case SUB_COMP:       /* Perform substraction on complex numbers */
		case MULT_COMP_COMP: /* Multiply 2 complex numbers */
			if (check_param_number(2, param_count))
			{
				complex *var1 = get_variable_by_name(params[0]);
				complex *var2 = get_variable_by_name(params[1]);
				if (var1 && var2)
				{
					switch (command)
					{
					case ADD_COMP:
						add_comp(var1, var2);
						break;
					case SUB_COMP:
						sub_comp(var1, var2);
						break;
					case MULT_COMP_COMP:
						mult_comp_comp(var1, var2);
						break;
					default:
						break;
					}
				}
			}
			break;
		case MULT_COMP_REAL: /* Multiply complex variable with a real number */
		case MULT_COMP_IMG:  /* Multiply complex variable with an imaginary number */
			if (check_param_number(2, param_count))
			{													 
				/* check if there are 2 parameters given */
				complex *var1 = get_variable_by_name(params[0]);
				if (var1)
				{
					char *err0 = NULL;
					double val = strtod(params[1], &err0); /* convert the second parameter to a double */
					/* return error if the parameter name is invalid */
					if (!(isspace((unsigned char)*err0) || *err0 == 0))
					{ 
						puts("Invalid parameter - not a number");
						break;
					}
					if (command == MULT_COMP_REAL) /* if command is for multiplying with real number */
						mult_comp_real(var1, val);
					else /* if command is for multiplying with imaginary number */
						mult_comp_img(var1, val);
				}
			}
			break;
		case STOP: /* command to stop the program */
			puts("\nProgram terminated - Bye!");
			return 0;
		default: /* Error/None: Error was printed, get another line from user */
			break;
		}
		printf(">> ");
	}
	puts("Please exit using the stop command.");
	return 0;
}