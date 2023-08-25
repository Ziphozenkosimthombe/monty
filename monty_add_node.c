#include "monty.h"

/**
 * add_node - node will be add to the stack
 * @stack: head stack
 * @n: new value
 *
 * Return: nothing
 */
void add_node(stack_t **stack, int n)
{
	stack_t *new_node, *au;

	au = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (au)
		au->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
