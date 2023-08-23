#include "monty.h"

/**
 * queue_node - It will add the node to astack_t head in queue_node
 * @head: header
 * @n: number of the node
 *
 * Return: The newly created node, if the memory allocaation it fails,
 * function return NULL.
 */
stack_t *queue_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (current)
	{
		if (current->next)
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
 * @head: header
 * @n: number of the new node
 *
 * Return: create new node, if creation fails,
 * the function will return NULL
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * print_stack - it will print the content of the stack_t head
 * @head: header
 *
 * Return: element of the list
 */
size_t print_stack(const stack_t *head)
{
	size_t i = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		i++;
	}

	return(i);
}

/**
 * free_stack - it will free the dlistint_t linked list
 * @head: header
 *
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
