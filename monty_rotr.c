#include "monty.h"

/**
 * opcode_rotr - the last node of stack_t head will be rotated
 * @stack: header stack
 * @line_counters: totala amount of line
 *
 * Return: nothing
 */
void opcode_rotr(stack_t **stack, unsigned int line_counters)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_counters;
	if (!stack || !*stack || !(*stack)->next)
		return;
	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
