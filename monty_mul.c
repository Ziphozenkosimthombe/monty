#include "monty.h"

/**
 * opcode_mul - It multiply the next top value by the top value
 * @head: The head given by the main
 * @line_counters: total amount of lines
 *
 * Return: nothing
 */
void opcode_mul(stack_t **head, unsigned int line_counters)
{
	int checker;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_counters);
		exit(EXIT_FAILURE);
		return;
	}

	checker = ((*head)->next->n) * ((*head)->n);
	opcode_pop(head, line_counters);
	(*head)->n = checker;
}
