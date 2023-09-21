#include "monty.h"

/**
 * _osam_queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_queue(stack_t **doubly, unsigned int curr_line)
{
    (void)doubly;
    (void)curr_line;

    osam_global_var.lifo = 0;
}

/**
 * _osam_stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_stack(stack_t **doubly, unsigned int curr_line)
{
    (void)doubly;
    (void)curr_line;

    osam_global_var.lifo = 1;
}

/**
 * _osam_add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_add(stack_t **doubly, unsigned int curr_line)
{
    int m = 0;
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        dprintf(2, "L%u: can't add, stack too short\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    aux = (*doubly)->next;
    aux->n += (*doubly)->n;
    _osam_pop(doubly, curr_line);
}

/**
 * _osam_nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_nop(stack_t **doubly, unsigned int curr_line)
{
    (void)doubly;
    (void)curr_line;
}

/**
 * _osam_sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_sub(stack_t **doubly, unsigned int curr_line)
{
    int m = 0;
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        dprintf(2, "L%u: can't sub, stack too short\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    aux = (*doubly)->next;
    aux->n -= (*doubly)->n;
    _osam_pop(doubly, curr_line);
}
