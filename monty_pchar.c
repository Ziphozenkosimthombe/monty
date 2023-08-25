#include "monty.h"

/**
 * opcode_pchar - the character at the top of the stack
 * will be printed
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_pchar(stack_t **stack, unsigned int amount)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
