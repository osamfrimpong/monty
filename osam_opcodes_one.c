#include "monty.h"

/**
 * _osam_push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_push(stack_t **doubly, unsigned int curr_line)
{
	char *message;
	int n, j;

	if (!osam_global_var.arg)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: usage: push integer\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	for (j = 0; osam_global_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(osam_global_var.arg[j]) && osam_global_var.arg[j] != '-')
		{
			message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
			snprintf(message, OSAM_MAX_BUFFER_SIZE,
					"L%u: usage: push integer\n", curr_line);
			osam_print_out(message, 2);
			free(message);
			osam_free_global_var(osam_global_var);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(osam_global_var.arg);

	if (osam_global_var.lifo == 1)
		osam_add_node_start(doubly, n);
	else
		osam_add_node_end(doubly, n);
}

/**
 * _osam_pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line numbers
 * Return: void
 */
void _osam_pall(stack_t **doubly, unsigned int curr_line)
{
	stack_t *aux;
	(void)curr_line;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _osam_pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_pint(stack_t **doubly, unsigned int curr_line)
{
	char *message;
	(void)curr_line;

	if (*doubly == NULL)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't pint, stack empty\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _osam_pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_pop(stack_t **doubly, unsigned int curr_line)
{
	char *message;
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't pop an empty stack\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _osam_swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_swap(stack_t **doubly, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't swap, stack too short\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
