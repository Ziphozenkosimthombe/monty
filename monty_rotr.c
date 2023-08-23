#include "monty.h"

/**
 * opcode_rotr - the last node of stack_t head will be rotated
 * @head: header stack
 * @line_counters: totala amount of line
 *
 * Return: nothing
 */
void opcode_rotr(stack_t **head, unsigned int line_counters)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_counters;
	if (!head || !*head || !(*head)->next)
		return;
	bottom = *head;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *head;
	bottom->prev = NULL;
	prev->next = NULL;
	(*head)->prev = bottom;
	*head = bottom;
}
