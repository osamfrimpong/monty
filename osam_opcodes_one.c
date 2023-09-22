#include "monty.h"

/**
 * _osam_push - pushes an element to the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_push(stack_t **linked_list_head, unsigned int curr_line)
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
        osam_add_node_start(linked_list_head, n);
    else
        osam_add_node_end(linked_list_head, n);
}

/**
 * _osam_pall - prints all values on the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line numbers
 * Return: void
 */
void _osam_pall(stack_t **linked_list_head, unsigned int curr_line)
{
    stack_t *new_node;
    (void)curr_line;

    new_node = *linked_list_head;

    while (new_node)
    {
        printf("%d\n", new_node->n);
        new_node = new_node->next;
    }
}

/**
 * _osam_pint - prints the value at the top of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_pint(stack_t **linked_list_head, unsigned int curr_line)
{
    char *message;
    (void)curr_line;

    if (*linked_list_head == NULL)
    {
        message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
        snprintf(message, OSAM_MAX_BUFFER_SIZE,
                 "L%u: can't pint, stack empty\n", curr_line);
        osam_print_out(message, 2);
        free(message);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*linked_list_head)->n);
}

/**
 * _osam_pop - removes the top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_pop(stack_t **linked_list_head, unsigned int curr_line)
{
    char *message;
    stack_t *new_node;

    if (linked_list_head == NULL || *linked_list_head == NULL)
    {
        message = malloc(sizeof(char) * OSAM_MAX_BUFFER_SIZE);
        snprintf(message, OSAM_MAX_BUFFER_SIZE,
                 "L%u: can't pop an empty stack\n", curr_line);
        osam_print_out(message, 2);
        free(message);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }
    new_node = *linked_list_head;
    *linked_list_head = (*linked_list_head)->next;
    free(new_node);
}

/**
 * _osam_swap - swaps the top two elements of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number
 * Return: void
 */
void _osam_swap(stack_t **linked_list_head, unsigned int curr_line)
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
                 "L%u: can't swap, stack too short\n", curr_line);
        osam_print_out(message, 2);
        free(message);
        osam_free_global_var(osam_global_var);
        exit(EXIT_FAILURE);
    }

    new_node = *linked_list_head;
    *linked_list_head = (*linked_list_head)->next;
    new_node->next = (*linked_list_head)->next;
    new_node->prev = *linked_list_head;
    (*linked_list_head)->next = new_node;
    (*linked_list_head)->prev = NULL;
}
