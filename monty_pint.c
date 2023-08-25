#include "monty.h"

/**
 * opcode_pint - the top will be printed
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_pint(stack_t **stack, unsigned int amount)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
