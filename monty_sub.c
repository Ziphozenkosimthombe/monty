#include "monty.h"

/**
 * opcode_sub - the subtration
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_sub(stack_t **stack, unsigned int amount)
{
	stack_t *au;
	int su, node;

	au = *stack;
	for (node = 0; au != NULL; node++)
		au = au->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	au = *stack;
	su = au->next->n - au->n;
	au->next->n = su;
	*stack = au->next;
	free(au);
}
