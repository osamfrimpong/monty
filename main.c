#include "monty.h"

osam_monty_global_t osam_global_var;

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
	ssize_t num_lines = 0;
	char *lines[2] = {NULL, NULL};
    char *message = "";

	file_desc = osam_check_input(argc, argv);
	osam_start_global_var(file_desc, &osam_global_var);
	num_lines = getline(&osam_global_var.text_buffer, &size, file_desc);
	while (num_lines != -1)
	{
		lines[0] = strtok(osam_global_var.text_buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = find_osam_opcode(lines[0]);
			if (!f)
			{
                snprintf(message, OSAM_MAX_BUFFER_SIZE, "L%u: unknown instruction %s\n", osam_global_var.curr_line,lines[0]);
		        osam_print_out(message, 2);
				osam_free_global_var(osam_global_var);
				exit(EXIT_FAILURE);
			}
			osam_global_var.arg = strtok(NULL, " \t\n");
			f(&osam_global_var.head, osam_global_var.curr_line);
		}
		num_lines = getline(&osam_global_var.text_buffer, &size, file_desc);
		osam_global_var.curr_line++;
	}

	osam_free_global_var(osam_global_var);

	return (0);
}
