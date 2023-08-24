#include "monty.h"

/**
 * opcode_swap - the data will be swap from top to the previous
 * @stack: the head that is given by the main
 * @amount: total amount of lines
 *
 * Return: nothing
 */
void opcode_swap(stack_t **stack, unsigned int amount)
{
	stack_t *temp = NULL;
	int temp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", amount);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp_n = temp->n;
	temp->n = temp_n;

	temp->n = temp->next->n;
	temp->next->n = temp_n;
}
