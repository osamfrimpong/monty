#include "monty.h"

/**
 * _osam_div - divides the second element by the top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_div(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *aux = NULL;

	aux = *linked_list_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't div, stack too short\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n == 0)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: division by zero\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	aux = (*linked_list_head)->next;
	aux->n /= (*linked_list_head)->n;
	_osam_pop(linked_list_head, curr_line);
}

/**
 * _osam_mul - multiplies the top element to
 * the second top element of the stack
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_mul(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *aux = NULL;

	aux = *linked_list_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{

		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't mul, stack too short\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	aux = (*linked_list_head)->next;
	aux->n *= (*linked_list_head)->n;
	_osam_pop(linked_list_head, curr_line);
}

/**
 * _osam_mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_mod(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *aux = NULL;

	aux = *linked_list_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't mod, stack too short\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n == 0)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: division by zero\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}

	aux = (*linked_list_head)->next;
	aux->n %= (*linked_list_head)->n;
	_osam_pop(linked_list_head, curr_line);
}
/**
 * _osam_pchar - print the char value of the first element
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_pchar(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;

	if (linked_list_head == NULL || *linked_list_head == NULL)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't pchar, stack empty\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}
	if ((*linked_list_head)->n < 0 || (*linked_list_head)->n >= 128)
	{
		message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
		snprintf(message, OSAM_MAX_BUFFER_SIZE,
				"L%u: can't pchar, value out of range\n", curr_line);
		osam_print_out(message, 2);
		free(message);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*linked_list_head)->n);
}

/**
 * _osam_pstr - prints the string of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_pstr(stack_t **linked_list_head, unsigned int curr_line)
{
	stack_t *aux;
	(void)curr_line;

	aux = *linked_list_head;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
