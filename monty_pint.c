#include "monty.h"

/**
 * opcode_pint - The value will be printed at the top of the head
 * @stack: given by the main
 * @amount: total amount of lines
 *
 * Return: nothing or void
 */
void opcode_pint(stack_t **stack, unsigned int amount)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d:  can't pint, stack empty\n", amount);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
