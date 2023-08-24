#include "monty.h"

/**
 * opcode_push - Its push the element into the head
 * @stack: head that is been given by the main
 * @amount: count that total of lines
 *
 * Return: void or nothing
 */
void opcode_push(stack_t **stack, unsigned int amount)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", amount);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
