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
    stack_t *aux = NULL;
    (void)curr_line;

    if (*linked_list_head == NULL)
        return;

    if ((*linked_list_head)->next == NULL)
        return;

    aux = *linked_list_head;

    for (; aux->next != NULL; aux = aux->next)
        ;

    aux->prev->next = NULL;
    aux->next = *linked_list_head;
    aux->prev = NULL;
    (*linked_list_head)->prev = aux;
    *linked_list_head = aux;
}
