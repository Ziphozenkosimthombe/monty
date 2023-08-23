#include  "monty.h"

/**
 * opcode_pall - It print the head
 * @head: The head that is given by the main
 * @line_counters: counts the total of lines
 *
 * Return: nothing
 */
void opcode_pall(stack_t **head, unsigned int
		line_counters __attribute__((unused)))
{
	print_stack(*head);
}
