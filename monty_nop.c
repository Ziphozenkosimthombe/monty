#include "monty.h"

/**
 * opcode_nop - do nothing
 * @stack: head stack
 * @amount: line counter
 *
 * Return: nothing
 */
void opcode_nop(stack_t **stack, unsigned int amount)
{
	(void) amount;
	(void) stack;
}
