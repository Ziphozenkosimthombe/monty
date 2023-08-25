#include "monty.h"

/**
 * opcode_mod - the rest of the division will be computes and
 * the second top element of the stack by the top element of the stack
 * @stack: head stack
 * @amount: counter lines
 *
 * Return: nothing
 */
void opcode_mod(stack_t **stack, unsigned int amount)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", amount);
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
	au = h->next->n % h->n;
	h->next->n = au;
	*stack = h->next;
	free(h);
}
