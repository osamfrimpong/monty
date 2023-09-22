#include "monty.h"

/**
 * _osam_queue - sets the format of the data to a queue (FIFO)
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_queue(stack_t **linked_list_head, unsigned int curr_line)
{
	(void)linked_list_head;
	(void)curr_line;

	osam_global_var.lifo = 0;
}

/**
 * _osam_stack - sets the format fo the data to a stack (LIFO)
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_stack(stack_t **linked_list_head, unsigned int curr_line)
{
	(void)linked_list_head;
	(void)curr_line;

	osam_global_var.lifo = 1;
}

/**
 * _osam_add - adds the top two elements of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_add(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *new_node = NULL;

	new_node = *linked_list_head;

	for (; new_node != NULL; new_node = new_node->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't add, stack too short\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n += (*linked_list_head)->n;
	_osam_pop(linked_list_head, curr_line);
}

/**
 * _osam_nop - doesn't do anythinhg
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_nop(stack_t **linked_list_head, unsigned int curr_line)
{
	(void)linked_list_head;
	(void)curr_line;
}

/**
 * _osam_sub - subtracts the top element to the second top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_sub(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *new_node = NULL;

	new_node = *linked_list_head;

	for (; new_node != NULL; new_node = new_node->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't sub, stack too short\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n -= (*linked_list_head)->n;
	_osam_pop(linked_list_head, curr_line);
}
