#include "monty.h"

/**
 * opcode_mod - the ramainder of the division will be computes
 * @stack: the head of the given main
 * @amount: total amount of lines
 *
 * Return: nothing
 */
void opcode_mod(stack_t **stack, unsigned int amount)
{
	int checker;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", amount);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", amount);
		exit(EXIT_FAILURE);
		return;
	}

	checker = ((*stack)->next->n) % ((*stack)->n);
	opcode_pop(stack, amount);
	(*stack)->n = checker;
}
