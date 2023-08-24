#include "monty.h"

/**
 * opcode_pchar - will print the int at the top of stack
 * @stack: stack given by the header
 * @amount: mount of lines
 *
 * Return: nothing
 */
void opcode_pchar(stack_t **stack, unsigned int amount)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", amount);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", amount);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
