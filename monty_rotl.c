#include "monty.h"

/**
 * opcode_rotl - the first element will be rotated
 * @stack: header
 * @line_counters: total amount of lines
 *
 * Return: nothing
 */
void opcode_rotl(stack_t **stack, unsigned int line_counters)
{
	stack_t *left;
	stack_t *right;

	(void) line_counters;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next)
		right = right->next;
	right->next = left;
	left->prev = right;
	*stack = left->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
