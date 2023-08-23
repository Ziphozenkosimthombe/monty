#include "monty.h"

/**
 * opcode_pop - it will pop everything  in the top element
 * of the head
 * @head: the head that is given by the main
 * @line_counters: This will be the line number for message error
 *
 * Return: nothing
 */
void opcode_pop(stack_t **head, unsigned int line_counters)
{
	stack_t *tmp = NULL;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_counters);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
	if (!*head)
		return;
	(*head)->prev = NULL;
}
