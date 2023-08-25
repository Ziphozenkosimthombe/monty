#include "monty.h"

/**
 * free_stack -the doubly linked list will be frees
 * @stack: stack of the head
 */

void free_stack(stack_t *stack)
{
	stack_t *au;

	au = stack;
	while (stack)
	{
		au = stack->next;
		free(stack);
		stack = au;
	}
}
