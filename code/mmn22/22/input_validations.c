#include <stdio.h>
#include <string.h>
#include "mycomp.h"

command_type get_command(char line[], char *params_out[3], int *param_count)
{
    command_type to_return;
    char *command, *rest;
    char line_copy[MAX_LINE_LENGTH];
	int total_line_length = strlen(line);
    command = strtok(line, "\t \n");

    if (command == NULL)
        return NONE;

    to_return = check_command_string(command);
    if (to_return == ERROR || to_return == STOP || strlen(command) == total_line_length-1) 
		return to_return;
    memcpy(line_copy, line, total_line_length);
    rest = command + strlen(command) + 1;
    if (*strtok(command + strlen(command)+1, "\t ") == ',') {
    	puts("Illegal comma");
    	return ERROR;
    }

    memcpy(line, line_copy, total_line_length);

	for (*param_count = 0; *param_count < MAX_param_COUNT && strlen(rest) > 0;) {
		char *first, *second, *curr_part;

		curr_part = strtok(rest, ",");
		rest = curr_part + strlen(curr_part) + 1;

		first = strtok(curr_part, "\t ");

		if (first == NULL || (rest < line+total_line_length && *rest == ',')) {
			puts("Multiple consecutive commas");
			return ERROR;
		}
		else if (*first == '\n')
			break;

		second = strtok(NULL, "\t ");
		if (second != NULL && *second != '\n') {
			puts("Missing comma");
			return ERROR;
		}

		if (*(first+strlen(first)-1) == '\n')
			first[strlen(first)-1] = '\0';

		params_out[(*param_count)++] = first;

		if (rest > line+total_line_length || *rest == '\n') 
			break;
	}

	if ((rest != NULL && strlen(rest) != 0 && rest < line+total_line_length)) {
		puts("Extraneous text after end of command");
		return ERROR;
	}

    return to_return;
}


command_type check_command_string(char command[])
{
    if (strcmp(command, "read_comp") == 0) 
		return READ_COMP;
    else if (strcmp(command, "print_comp") == 0) 
		return PRINT_COMP;
    else if (strcmp(command, "add_comp") == 0)
		return ADD_COMP;
    else if (strcmp(command, "sub_comp") == 0)
		return SUB_COMP;
    else if (strcmp(command, "mult_comp_real") == 0)
		return MULT_COMP_REAL;
    else if (strcmp(command, "mult_comp_img") == 0)	
		return MULT_COMP_IMG;
    else if (strcmp(command, "mult_comp_comp") == 0)
		return MULT_COMP_COMP;
    else if (strcmp(command, "abs_comp") == 0)
		return ABS_COMP;
    else if (strcmp(command, "stop") == 0)
		return STOP;
    else
    {
        puts("Undefined command name");
        return ERROR;
    }
}

complex *get_variable_by_name(char *name) {
	if (strlen(name) == 1 && name[0] >= 'A' && name[0] <= ('A'+VARIABLE_COUNT))
		return complexes[name[0] - 'A'];
	puts("Undefined complex variable");
	return NULL;
}

boolean check_param_number(int expected_param_count, int actual_param_count) {
	if (expected_param_count == actual_param_count) 
		return TRUE;
	else if (expected_param_count < actual_param_count) 
		puts("Extraneous text after end of command.");
	else 
		puts("Missing parameter");
	return FALSE;
}
