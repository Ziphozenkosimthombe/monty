#include "monty.h"

/**
 * opcode_pchar - print all the intehers at the top of the stack as charecter
 * @head: the head that is given by the main
 * @line_counters: total amount of lines
 *
 * Return: nothing
 */
void opcode_pchar(stack_t **head, unsigned int line_counters)
{
	if (!head || !((*head)))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_counters);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*head)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_counters);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*head)->n);
}
