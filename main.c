#include "monty.h"

osam_monty_global_t global_var;

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file_desc;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	file_desc = osam_check_input(argc, argv);
	osam_start_global_var(file_desc, &global_var);
	nlines = getline(&global_var.text_buffer, &size, file_desc);
	while (nlines != -1)
	{
		lines[0] = strtok(global_var.text_buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = find_osam_opcode(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global_var.curr_line);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				osam_free_global_var(global_var);
				exit(EXIT_FAILURE);
			}
			global_var.arg = strtok(NULL, " \t\n");
			f(&global_var.head, global_var.curr_line);
		}
		nlines = getline(&global_var.text_buffer, &size, file_desc);
		global_var.curr_line++;
	}

	osam_free_global_var(global_var);

	return (0);
}
