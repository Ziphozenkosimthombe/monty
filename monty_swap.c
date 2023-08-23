#include "monty.h"

/**
 * opcode_swap - the data will be swap from top to the previous
 * @head: the head that is given by the main
 * @line_counters: total amount of lines
 *
 * Return: nothing
 */
void opcode_swap(stack_t **head, unsigned int line_counters)
{
	stack_t *tmp = NULL;
	int tmp_i = 0;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_counters);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	tmp_i = tmp->n;
	tmp->n = tmp_i;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_i;
}
