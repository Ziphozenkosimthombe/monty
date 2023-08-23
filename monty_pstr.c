#include "monty.h"

/**
 * opcode_pstr - it will print all the content of the stack_t
 * head as a string
 * @head: the head that is given by the main
 * @line_counters: the total amount of lines for the
 * error message
 *
 * Return: nothing
 */
void opcode_pstr(stack_t **head, unsigned int
		line_counters __attribute__((unused)))
{
	stack_t *current = *head;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
