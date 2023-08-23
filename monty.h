#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define INSTRUCTIONS              \
	{                           \
		{"opcode_push", opcode_push},       \
		    {"opcode_rotr", opcode_rotr},   \
		    {"opcode_rotl", opcode_rotl},   \
		    {"opcode_pstr", opcode_pstr},     \
		    {"opcode_pchar", opcode_pchar},   \
		    {"opcode_nop", opcode_nop},     \
		    {"opcode_div", opcode_div},    \
		    {"opcode_mul", opcode_mul},    \
		    {"opcode_add", opcode_add},    \
		    {"opcode_sub", opcode_sub},    \
		    {"opcode_mod", opcode_mod},     \
		    {"opcode_swap", opcode_swap}, \
		    {"opcode_pint", opcode_pint},   \
		    {"opcode_pop", opcode_pop},   \
		    {"opcode_pall", opcode_pall},   \
		{                     \
			NULL, NULL      \
		}                     \
	}


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct help - This is the argument for the current opcode
 * @data_struct: stack, queue and stack mode
 * @argument: The string argument
 *
 * Description: The structure for the global that uses to pass data around the
 * functions easily
 */

typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;
int main(int argc, char **argv);
int is_digit(char *string);
int isnumber(char *str);

void opcode(stack_t **head, char *str, unsigned int line_counters);

void opcode_rotr(stack_t **head, unsigned int line_counters);
void opcode_pchar(stack_t **head, unsigned int line_counters);
void opcode_rotl(stack_t **head, unsigned int line_counters);
void opcode_pstr(stack_t **head, unsigned int line_counters);

void opcode_mod(stack_t **head, unsigned int line_counters);
void opcode_div(stack_t **head, unsigned int line_counters);
void opcode_sub(stack_t **head, unsigned int line_counters);
void opcode_add(stack_t **head, unsigned int line_counters);
void opcode_mul(stack_t **head, unsigned int line_counters);

void opcode_push(stack_t **head, unsigned int line_counters);
void opcode_swap(stack_t **head, unsigned int line_counters);
void opcode_nop(stack_t **head, unsigned int line_counters);
void opcode_pop(stack_t **head, unsigned int line_counters);
void opcode_pint(stack_t **gead, unsigned int line_counters);
void opcode_pall(stack_t **head, unsigned int line_counters);


stack_t *add_node(stack_t **head, const int n);
size_t print_stack(const stack_t *head);
stack_t *queue_node(stack_t **head, const int n);
void free_stack(stack_t *head);


#endif