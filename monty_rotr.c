#include "monty.h"

/**
 * opcode_rotr - the stack to the bottom will be rotated
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_rotr(stack_t **stack, __attribute__((unused)) unsigned int amount)
{
	stack_t *cpy;

	cpy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *stack;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*stack)->prev = cpy;
	(*stack) = cpy;
}
