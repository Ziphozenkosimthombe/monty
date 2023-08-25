#include "monty.h"

/**
 * opcode_pstr - the str will be printed starting at the top
 * of the stack follow by a new stack
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_pstr(stack_t **stack, unsigned int amount)
{
	stack_t *h;
	(void)amount;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
