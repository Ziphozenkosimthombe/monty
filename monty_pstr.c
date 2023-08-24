#include "monty.h"

/**
 * opcode_pstr - it will print all the content of the stack_t
 * head as a string
 * @stack: the head that is given by the main
 * @amount: the total amount of lines for the
 * error message
 *
 * Return: nothing
 */
void opcode_pstr(stack_t **stack, unsigned int amount __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
