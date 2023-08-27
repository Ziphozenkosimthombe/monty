#include "monty.h"

/**
 * execute - the opcode will be executed
 * @stack: linked list - stack
 * @amount: line counter
 * @file: monty file pointer
 * @content: the content line
 *
 * Return: nothing
 */
int execute(char *content, stack_t **stack, unsigned int amount, FILE *file)
{
	instruction_t opst[] = {
				{"push", opcode_push}, {"pall", opcode_pall}, {"pint", opcode_pint},
				{"pop", opcode_pop},
				{"swap", opcode_swap},
				{"add", opcode_add},
				{"nop", opcode_nop},
				{"sub", opcode_sub},
				{"div", opcode_div},
				{"mul", opcode_mul},
				{"mod", opcode_mod},
				{"pchar", opcode_pchar},
				{"pstr", opcode_pstr},
				{"rotl", opcode_rotl},
				{"rotr", opcode_rotr},
				{"queue", opcode_queue},
				{"stack", opcode_stack},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[a].opcode && op)
	{
		if (strcmp(op, opst[a].opcode) == 0)
		{
			opst[a].f(stack, amount);
			return (0);
		}
		a++;
	}
	if (op && opst[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", amount, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1); }
