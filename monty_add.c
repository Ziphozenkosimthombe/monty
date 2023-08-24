#include "monty.h"

/**
 * opcode_add - it will add the first two node at the head
 * @stack: head given by the main
 * @amount: counnts the total lines
 *
 * Return: nothing or void
 */
void opcode_add(stack_t **stack, unsigned int amount)
{
	int checker;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", amount);
		exit(EXIT_FAILURE);
	}

	checker = ((*stack)->next->n) + ((*stack)->n);
	opcode_pop(stack, amount);
	(*stack)->n = checker;
}
