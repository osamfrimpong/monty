#include "monty.h"

/**
 *osam_add_node_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *osam_add_node_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		osam_free_global_var(osam_global_var);
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 *osam_add_node_start - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *osam_add_node_start(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * osam_free_d_linked_list - frees the doubly linked list
 *
 * @head: head of the doubly linked list
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
