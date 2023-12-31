#include "monty.h"

/**
 *osam_add_node_end - add a node at the end of the
 *linked_list_head link list
 *@head: first position of linked list
 *@n: integer to add
 *Return: a linked_list_head linked list
 */
stack_t *osam_add_node_end(stack_t **head, const int n)
{
	stack_t *temporary_node, *new_node;

	if (head == NULL)
		return (NULL);
	temporary_node = malloc(sizeof(stack_t));
	if (!temporary_node)
	{
		osam_print_out("Error: malloc failed\n", 2);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}
	temporary_node->n = n;

	if (*head == NULL)
	{
		temporary_node->next = *head;
		temporary_node->prev = NULL;
		*head = temporary_node;
		return (*head);
	}
	new_node = *head;
	while (new_node->next)
		new_node = new_node->next;
	temporary_node->next = new_node->next;
	temporary_node->prev = new_node;
	new_node->next = temporary_node;
	return (new_node->next);
}

/**
 *osam_add_node_start - add a node at the
 *begining of the linked_list_head link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a linked_list_head linked list
 */
stack_t *osam_add_node_start(stack_t **head, const int n)
{
	stack_t *temporary_node;

	if (head == NULL)
		return (NULL);
	temporary_node = malloc(sizeof(stack_t));
	if (!temporary_node)
	{
		osam_print_out("Error: malloc failed\n", 2);
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}
	temporary_node->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temporary_node->next = *head;
		temporary_node->prev = NULL;
		*head = temporary_node;
		return (*head);
	}
	(*head)->prev = temporary_node;
	temporary_node->next = (*head);
	temporary_node->prev = NULL;
	*head = temporary_node;
	return (*head);
}

/**
 * osam_free_d_linked_list - frees the linked_list_head linked list
 *
 * @head: head of the linked_list_head linked list
 * Return: void
 */
void osam_free_d_linked_list(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
