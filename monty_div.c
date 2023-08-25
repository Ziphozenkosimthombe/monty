#include "monty.h"

/**
 * opcode_div - the to 2 element of the stack will divided
 * @stack: head stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_div(stack_t **stack, unsigned int amount)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	au = h->next->n / h->n;
	h->next->n = au;
	*stack = h->next;
	free(h);
}
