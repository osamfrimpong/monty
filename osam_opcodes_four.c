#include "monty.h"

/**
 * _osam_rotl - rotates the first element to
 * the bottom and  the second to the top
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _osam_rotl(stack_t **linked_list_head, unsigned int curr_line)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)curr_line;

	if (*linked_list_head == NULL)
		return;

	if ((*linked_list_head)->next == NULL)
		return;

	aux1 = (*linked_list_head)->next;
	aux2 = *linked_list_head;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *linked_list_head;
	(*linked_list_head)->next = NULL;
	(*linked_list_head)->prev = aux2;
	*linked_list_head = aux1;
}

/**
 * _osam_rotr - reverse the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_rotr(stack_t **linked_list_head, unsigned int curr_line)
{
	stack_t *new_node = NULL;
	(void)curr_line;

	if (*linked_list_head == NULL)
		return;

	if ((*linked_list_head)->next == NULL)
		return;

	new_node = *linked_list_head;

	for (; new_node->next != NULL; new_node = new_node->next)
		;

	new_node->prev->next = NULL;
	new_node->next = *linked_list_head;
	new_node->prev = NULL;
	(*linked_list_head)->prev = new_node;
	*linked_list_head = new_node;
}
