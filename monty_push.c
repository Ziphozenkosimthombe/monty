#include "monty.h"

/**
 * opcode_push - Its push the element into the head
 * @head: head that is been given by the main
 * @line_counters: count that total of lines
 *
 * Return: void or nothing
 */
void opcode_push(stack_t **head, unsigned int line_counters)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counters);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(head, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(head, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
