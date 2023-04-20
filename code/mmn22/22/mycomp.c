#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mycomp.h"

int main() {
	char line[MAX_LINE_LENGTH], *params[3];
	int param_count, i;
	command_type command;

	for (i = 0; i < VARIABLE_COUNT; i++) {
		complexes[i] = empty_comp();
	}

	printf("Type a command and press enter to execute:\n>> ");


	while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
		printf("%s", line);
		command = get_command(line, params, &param_count);

		switch (command) {
			case READ_COMP:
				if (check_param_number(3, param_count)) {
					complex *var = get_variable_by_name(params[0]);
					if (var) {
						char *err0 = NULL, *err1 = NULL;
						double real_val = strtod(params[1], &err0);
						double img_val = strtod(params[2], &err1);
						if (!(isspace((unsigned char) *err0) || *err0 == 0) ||
						    !(isspace((unsigned char) *err1) || *err1 == 0)) {
							puts("Invalid parameter - not a number");
							break;
						}
						read_comp(var, real_val, img_val);
					}
				}
				break;
			case PRINT_COMP:
			case ABS_COMP:
				if (check_param_number(1, param_count)) {
					complex *var = get_variable_by_name(params[0]);
					if (var) {
						if (command == PRINT_COMP)
							print_comp(var);
						else
							printf("%.2f", abs_comp(var));
					}
				}
				break;
			case ADD_COMP:
			case SUB_COMP:
			case MULT_COMP_COMP:
				if (check_param_number(2, param_count)) {
					complex *var1 = get_variable_by_name(params[0]);
					complex *var2 = get_variable_by_name(params[1]);
					if (var1 && var2) {
						switch (command) {
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
			case MULT_COMP_REAL:
			case MULT_COMP_IMG:
				if (check_param_number(2, param_count)) {
					complex *var1 = get_variable_by_name(params[0]);
					if (var1) {
						char *err0 = NULL;
						double val = strtod(params[1], &err0);
						if (!(isspace((unsigned char) *err0) || *err0 == 0)) {
							puts("Invalid parameter - not a number");
							break;
						}
						if (command == MULT_COMP_REAL)
							mult_comp_real(var1, val);
						else
							mult_comp_img(var1, val);
					}
				}
				break;
			case STOP:
				puts("\nGoodbye!");
				return 0;
			default: /* Error/None: Error was printed, get another line from user */
				break;
		}
		printf(">> ");
	}
	puts("Please exit using the stop command.");
	return 0;
}