#include "monty.h"

/**
 * opcode_add - it will add the first two node at the head
 * @head: head given by the main
 * @line_counters: counnts the total lines
 *
 * Return: nothing or void
 */
void opcode_add(stack_t **head, unsigned int line_counters)
{
	int checker;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counters);
		exit(EXIT_FAILURE);
	}

	checker = ((*head)->next->n) + ((*head)->n);
	opcode_pop(head, line_counters);
	(*head)->n = checker;
}
