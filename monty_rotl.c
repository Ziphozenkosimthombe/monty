#include "monty.h"

/**
 * opcode_rotl - the first element will be rotated
 * @head: header
 * @line_counters: total amount of lines
 *
 * Return: nothing
 */
void opcode_rotl(stack_t **head, unsigned int line_counters)
{
	stack_t *left;
	stack_t *right;

	(void) line_counters;
	if (!head || !*head || !(*head)->next)
		return;

	left = right = *head;

	while (right->next)
		right = right->next;
	right->next = left;
	left->prev = right;
	*head = left->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}
