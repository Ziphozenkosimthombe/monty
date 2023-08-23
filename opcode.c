#include "./monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * opcode - function that is in the charge of running builtins
 * @head: head given by the main
 * @str: The string to be compare
 * @line_counters: total amount of the lines
 *
 * Return: void
 */
void opcode(stack_t **head, char *str, unsigned int line_counters)
{
	int n = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "head"))
	{
		global.data_struct = 1;
		return;
	}

	while (op[n].opcode)
	{
		if (strcmp(op[n].opcode, str) == 0)
		{
			op[n].f(head, line_counters);
			return;
		}
		n++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_counters, str);
	exit(EXIT_FAILURE);
}
