#include "monty.h"

/**
 * osam_print_out - prints to terminal
 * @error_message: pointer to message to write
 * Return: void
*/

void osam_print_out(char *message, int message_type)
{
	write(message_type, message, strlen(message));
}

/**
 * osam_free_global_var - frees the global variables
 * Return: void
 */
void osam_free_global_var(osam_monty_global_t global_var)
{
	osam_free_d_linked_list(global_var.head);
	free(global_var.text_buffer);
	fclose(global_var.file_desc);
}

/**
 * start_vglo - initializes the global variables
 *
 * @file_desc: file descriptor
 * Return: no return
 */
void osam_start_global_var(FILE *file_desc, osam_monty_global_t *global_var)
{
	global_var->lifo = 1;
	global_var->curr_line = 1;
	global_var->arg = NULL;
	global_var->head = NULL;
	global_var->file_desc = file_desc;
	global_var->text_buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *osam_check_input(int argc, char *argv[])
{
	FILE *file_desc;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_desc = fopen(argv[1], "r");

	if (file_desc == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file_desc);
}

/**
 * find_osam_opcode - selects the correct opcode to execute
 *
 * @opcode: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*find_osam_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _osam_push},
		{"pall", _osam_pall},
		{"pint", _osam_pint},
		{"pop", _osam_pop},
		{"swap", _osam_swap},
		{"queue", _osam_queue},
		{"stack", _osam_stack},
		{"add", _osam_add},
		{"nop", _osam_nop},
		{"sub", _osam_sub},
		{"mul", _osam_mul},
		{"div", _osam_div},
		{"mod", _osam_mod},
		{"pchar", _osam_pchar},
		{"pstr", _osam_pstr},
		{"rotl", _osam_rotl},
		{"rotr", _osam_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
			break;
	}

	return (instruct[i].f);
}
