#include "monty.h"

/**
 * opcode_pint - The value will be printed at the top of the head
 * @head: given by the main
 * @line_counters: total amount of lines
 *
 * Return: nothing or void
 */
void opcode_pint(stack_t **head, unsigned int line_counters)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%d:  can't pint, stack empty\n", line_counters);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
