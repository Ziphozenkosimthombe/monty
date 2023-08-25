#include "monty.h"

/**
 * opcode_pop - the top will be printed
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_pop(stack_t **stack, unsigned int amount)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
