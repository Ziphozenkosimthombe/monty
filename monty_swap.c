#include "monty.h"

/**
 * opcode_swap - the 2 element of stack will be added
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_swap(stack_t **stack, unsigned int amount)
{
	stack_t *h;
	int length = 0, au;

	h = *stack;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	au = h->n;
	h->n = h->next->n;
	h->next->n = au;
}
