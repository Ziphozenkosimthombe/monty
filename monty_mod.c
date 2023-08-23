#include "monty.h"

/**
 * opcode_mod - the ramainder of the division will be computes
 * @head: the head of the given main
 * @line_counters: total amount of lines
 *
 * Return: nothing
 */
void opcode_mod(stack_t **head, unsigned int line_counters)
{
	int checker;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_counters);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*head)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counters);
		exit(EXIT_FAILURE);
		return;
	}

	checker = ((*head)->next->n) % ((*head)->n);
	opcode_pop(head, line_counters);
	(*head)->n = checker;
}
