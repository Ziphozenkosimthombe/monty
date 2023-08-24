#include "monty.h"

/**
 * opcode_sub - the node of the head will be substracted
 * @stack: the head that is given by the main
 * @amount: total amount of the lines
 *
 * Return: nothing
 */
void opcode_sub(stack_t **stack, unsigned int amount)
{
	int checker;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", amount);
		exit(EXIT_FAILURE);
	}

	checker = ((*stack)->next->n) - ((*stack)->n);
	opcode_pop(stack, amount);
	(*stack)->n = checker;
}
