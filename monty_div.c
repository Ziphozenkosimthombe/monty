#include "monty.h"

/**
 * opcode_div - it will divide the next top value by the top value
 * @stack: the head given by the main
 * @amount: count the total amount lines
 *
 * Return: nothing
 */
void opcode_div(stack_t **stack, unsigned int amount)
{
	int checker;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", amount);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", amount);
		exit(EXIT_FAILURE);
		return;
	}

	checker = ((*stack)->next->n) / ((*stack)->n);
	opcode_pop(stack, amount);
	(*stack)->n = checker;
}
