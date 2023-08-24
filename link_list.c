#include "monty.h"

/**
 * queue_node - It will add the node to astack_t head in queue_node
 * @stack: header
 * @n: number of the node
 *
 * Return: The newly created node, if the memory allocaation it fails,
 * function return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}
	return (new);
}

/**
 * add_node - It will add the node at the start of the stack_t head
 * @stack: header
 * @n: number of the new node
 *
 * Return: create new node, if creation fails,
 * the function will return NULL
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 * print_stack - it will print the content of the stack_t head
 * @stack: header
 *
 * Return: element of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t i = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		i++;
	}

	return (i);
}

/**
 * free_stack - it will free the dlistint_t linked list
 * @stack: header
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
