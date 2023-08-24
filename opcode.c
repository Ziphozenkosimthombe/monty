#include "./monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * opcode - function that is in the charge of running builtins
 * @stack: head given by the main
 * @str: The string to be compare
 * @amount: total amount of the lines
 *
 * Return: void
 */
void opcode(stack_t **stack, char *str, unsigned int amount)
{
	int n = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[n].opcode)
	{
		if (strcmp(op[n].opcode, str) == 0)
		{
			op[n].f(stack, amount);
			return;
		}
		n++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", amount, str);
	exit(EXIT_FAILURE);
}
