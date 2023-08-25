#include "monty.h"

/**
 * opcode_rotl - the stack at the top will be rotated
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_rotl(stack_t **stack, __attribute__((unused)) unsigned int amount)
{
	stack_t *temp = *stack, *au;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	au = (*stack)->next;
	au->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = au;
}
