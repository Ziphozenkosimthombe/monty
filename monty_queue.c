#include "monty.h"

/**
 * opcode_queue - the top will be printed
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_queue(stack_t **stack, unsigned int amount)
{
	(void)stack;
	(void)amount;
	bus.lifi = 1;
}
/**
 * add_queue - the tail stack will add the node
 *
 * @n: new value
 * @stack: head of stack
 *  Return: nothing
 */
void add_queue(stack_t **stack, int n)
{
	stack_t *new_node, *au;

	au = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (au)
	{
		while (au->next)
			au = au->next;
	}
	if (!au)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		au->next = new_node;
		new_node->prev = au;
	}
}
