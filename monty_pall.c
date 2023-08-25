#include "monty.h"

/**
 * opcode_pall - the stack will be printed
 * @stack: head of stack
 * @amount: didn't used
 *
 * Return: nothing
 */
void opcode_pall(stack_t **stack, unsigned int amount)
{
	stack_t *h;
	(void)amount;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
