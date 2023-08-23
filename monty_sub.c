#include "monty.h"

/**
 * opcode_sub - the node of the head will be substracted
 * @head: the head that is given by the main
 * @line_counters: total amount of the lines
 *
 * Return: nothing
 */
void opcode_sub(stack_t **head, unsigned int line_counters)
{
	int checker;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_counters);
		exit(EXIT_FAILURE);
	}

	checker = ((*head)->next->n) - ((*head)->n);
	opcode_pop(head, line_counters);
	(*head)->n = checker;
}
