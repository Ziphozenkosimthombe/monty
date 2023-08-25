#include "monty.h"

/**
 * opcode_push - the node will be added to the stack
 * @stack: head of stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_push(stack_t **stack, unsigned int amount)
{
	int a, b = 0, flag = 0;

	if ( bus.arg)
	{
		if (bus.arg[0] == '-')
			b++;
		for (; bus.arg[b] != '\0'; b++)
		{
			if (bus.arg[b] > 57 || bus.arg[b] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", amount);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", amount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(stack, a);
	else
		add_queue(stack, a);
}
