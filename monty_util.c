#include "monty.h"

/**
 * is_digit - will check that the string is a digit
 * @string: stirng to be checked
 *
 * Return: 1if success, o if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
/**
 * isnumber - the string will be check if it is the number
 * @str: string
 *
 * Return: 1 if the string is number ,or 0 if not
 */
int isnumber(char *str)
{
	int n;

	if (!str)
		return (0);
	for (n = 0; str[n]; n++)
		if (n < '0' || n > '9')
			return (0);
	return (1);
}
