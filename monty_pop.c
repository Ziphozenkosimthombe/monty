#include "monty.h"

/**
 * opcode_pop - it will pop everything  in the top element
 * of the head
 * @stack: the head that is given by the main
 * @amount: This will be the line number for message error
 *
 * Return: nothing
 */
void opcode_pop(stack_t **stack, unsigned int amount)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", amount);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
