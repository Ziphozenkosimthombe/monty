#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_error(char *argv);
void error_usage(void);
int stat = 0;

/**
 * main - The entry pointer
 * @argv: The list of the argument that will be passed to our program
 * @argc: The amount of the argc
 *
 * Return: void
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int amount = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (stat)
			break;
		if (*buffer == '\n')
		{
			amount++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			amount++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, amount);
		amount++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - It print the error file message
 * @argv: The given by the main
 *
 * Desc: It print the message if no possible to open the file
 * Return: void
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage  - It prints the usage of message and exits
 *
 * Desc: if the user doesn't give any file or more than
 * one argument to the program
 *
 * Return: void
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
