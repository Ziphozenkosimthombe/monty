#include "monty.h"

/**
 * opcode_add - the top 2 element of the stack will be add
 * @stack: stack head
 * @amount: line counter
 * Return: nothing
 */
void opcode_add(stack_t **stack, unsigned int amount)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	au = h->n + h->next->n;
	h->next->n = au;
	*stack = h->next;
	free(h);
}
