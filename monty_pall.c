#include  "monty.h"

/**
 * opcode_pall - It print the head
 * @stack: The head that is given by the main
 * @amount: counts the total of lines
 *
 * Return: nothing
 */
void opcode_pall(stack_t **stack, unsigned int amount __attribute__((unused)))
{
	print_stack(*stack);
}
