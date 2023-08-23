#include "monty.h"

/**
 * opcode_div - it will divide the next top value by the top value
 * @head: the head given by the main
 * @line_counters: count the total amount lines
 *
 * Return: nothing
 */
void opcode_div(stack_t **head, unsigned int line_counters)
{
	int checker;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_counters);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counters);
		exit(EXIT_FAILURE);
		;
		return;
	}

	checker = ((*head)->next->n) / ((*head)->n);
	opcode_pop(head, line_counters);
	(*head)->n = checker;
}
