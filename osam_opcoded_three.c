#include "monty.h"

/**
 * _osam_div - divides the second element by the top element of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_div(stack_t **doubly, unsigned int curr_line)
{
    int m = 0;
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        dprintf(2, "L%u: can't div, stack too short\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    if ((*doubly)->n == 0)
    {
        dprintf(2, "L%u: division by zero\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    aux = (*doubly)->next;
    aux->n /= (*doubly)->n;
    _osam_pop(doubly, curr_line);
}

/**
 * _osam_mul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_mul(stack_t **doubly, unsigned int curr_line)
{
    int m = 0;
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        dprintf(2, "L%u: can't mul, stack too short\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    aux = (*doubly)->next;
    aux->n *= (*doubly)->n;
    _osam_pop(doubly, curr_line);
}

/**
 * _osam_mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_mod(stack_t **doubly, unsigned int curr_line)
{
    int m = 0;
    stack_t *aux = NULL;

    aux = *doubly;

    for (; aux != NULL; aux = aux->next, m++)
        ;

    if (m < 2)
    {
        dprintf(2, "L%u: can't mod, stack too short\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    if ((*doubly)->n == 0)
    {
        dprintf(2, "L%u: division by zero\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    aux = (*doubly)->next;
    aux->n %= (*doubly)->n;
    _osam_pop(doubly, curr_line);
}
/**
 * _osam_pchar - print the char value of the first element
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_pchar(stack_t **doubly, unsigned int curr_line)
{
    if (doubly == NULL || *doubly == NULL)
    {
        dprintf(2, "L%u: can't pchar, stack empty\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }
    if ((*doubly)->n < 0 || (*doubly)->n >= 128)
    {
        dprintf(2, "L%u: can't pchar, value out of range\n", curr_line);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (*doubly)->n);
}

/**
 * _osam_pstr - prints the string of the stack
 *
 * @doubly: head of the linked list
 * @curr_line: line number;
 * Return: no return
 */
void _osam_pstr(stack_t **doubly, unsigned int curr_line)
{
    stack_t *aux;
    (void)curr_line;

    aux = *doubly;

    while (aux && aux->n > 0 && aux->n < 128)
    {
        printf("%c", aux->n);
        aux = aux->next;
    }

    printf("\n");
}
