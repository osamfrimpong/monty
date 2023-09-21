#include "monty.h"

/**
 * osam_free_global_var - frees the global variables
 * Return: void
 */
void osam_free_global_var(osam_monty_global_t global_var)
{
	osam(global_var.head);
	free(global_var.text_buffer);
	fclose(global_var.file_desc);
}

/**
 * start_vglo - initializes the global variables
 *
 * @file_desc: file descriptor
 * Return: no return
 */
void osam_start_global_var(FILE *file_desc, osam_monty_global_t global_var)
{
	global_var.lifo = 1;
	global_var.curr_line = 1;
	global_var.arg = NULL;
	global_var.head = NULL;
	global_var.file_desc = file_desc;
	global_var.text_buffer = NULL;
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
