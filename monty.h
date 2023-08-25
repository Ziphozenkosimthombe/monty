#ifndef MONTY_H
#define MONTY_H
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

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
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;


void opcode_push(stack_t **stack, unsigned int amount);
void opcode_pall(stack_t **stack, unsigned int amount);
void opcode_pint(stack_t **stack, unsigned int amount);
int execute(char *content, stack_t **stack, unsigned int amount, FILE *file);
void free_stack(stack_t *stack);
void opcode_pop(stack_t **stack, unsigned int amount);
void opcode_swap(stack_t **stack, unsigned int amount);
void opcode_add(stack_t **stack, unsigned int amount);
void opcode_nop(stack_t **stack, unsigned int amount);
void opcode_sub(stack_t **stack, unsigned int amount);
void opcode_div(stack_t **stack, unsigned int amount);
void opcode_mul(stack_t **stack, unsigned int amount);
void opcode_mod(stack_t **stack, unsigned int amount);
void opcode_pchar(stack_t **stack, unsigned int amount);
void opcode_pstr(stack_t **stack, unsigned int amount);
void opcode_rotl(stack_t **stack, unsigned int amount);
void opcode_rotr(stack_t **stack, __attribute__((unused)) unsigned int amount);
void add_node(stack_t **stack, int n);
void add_queue(stack_t **stack, int n);
void opcode_queue(stack_t **stack, unsigned int amount);
void opcode_stack(stack_t **stack, unsigned int amount);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);

#endif
