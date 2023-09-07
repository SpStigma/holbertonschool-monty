#include "monty.h"

/**
 * integer_valid - check if it is an integer
 * @str: the string to check
 * Return: 1 or -1
 */
int integer_valid(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && str[i] != '-')
		{
			return (-1);
		}
	}
	return (1);
}

