#ifndef MAIN_OSAM_MONTY_H_
#define MAIN_OSAM_MONTY_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define OSAM_MAX_BUFFER_SIZE 1024

/**
 * struct stack_s - d_linked_list_head linked
 * list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: d_linked_list_head linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - structure to store opcode functions
 * @lifo: is stack or queue
 * @curr_line: current line
 * @arg: second parameter inside the current line
 * @head: d_linked_list_head linked list
 * @file_desc: file descriptor
 * @text_buffer: input text
 *
 * Description: d_linked_list_head linked list node structure
 * for osam-monty
 */
typedef struct globals
{
	int lifo;
	unsigned int curr_line;
	char *arg;
	stack_t *head;
	FILE *file_desc;
	char *text_buffer;
} osam_monty_global_t;

extern osam_monty_global_t osam_global_var;

/* general utilities functions*/
void osam_print_out(char *message, int message_type);
void osam_free_global_var(osam_monty_global_t global_var);
void osam_start_global_var(FILE *file_desc, osam_monty_global_t *global_var);
FILE *osam_check_input(int argc, char *argv[]);

/* find specific opcode function to execute*/
void (*find_osam_opcode(char *opcode))(stack_t **stack,
									   unsigned int line_number);

void _osam_push(stack_t **d_linked_list_head_stack, unsigned int line_number);
void _osam_pall(stack_t **d_linked_list_head_stack, unsigned int line_number);
void _osam_pint(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_pop(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_swap(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_queue(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_stack(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_add(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_nop(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_sub(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_div(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_mul(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_mod(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_pchar(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_pstr(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_rotl(stack_t **d_linked_list_head, unsigned int line_number);
void _osam_rotr(stack_t **d_linked_list_head, unsigned int line_number);

/* helper functions for linked_list_head linked lists manipulation */
stack_t *osam_add_node_end(stack_t **head, const int n);
stack_t *osam_add_node_start(stack_t **head, const int n);
void osam_free_d_linked_list(stack_t *head);
#endif /* MAIN_OSAM_MONTY_H_ */
