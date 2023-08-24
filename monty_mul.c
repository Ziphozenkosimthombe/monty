#include "monty.h"

/**
 * opcode_mul - It multiply the next top value by the top value
 * @stack: The head given by the main
 * @amount: total amount of lines
 *
 * Return: nothing
 */
void opcode_mul(stack_t **stack, unsigned int amount)
{
	int checker;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", amount);
		exit(EXIT_FAILURE);
		return;
	}

	checker = ((*stack)->next->n) * ((*stack)->n);
	opcode_pop(stack, amount);
	(*stack)->n = checker;
}
