#include "shell.h"

/**
 * fix_comments - Checks if the string is a comment
 * @buffer: The string to check and fix a null byte at point of #
 * Return: Void
 */

void fix_comments(char *buffer)
{
	int i = 0;

	while (buffer[i])
	{
		if (i > 0 && buffer[i] == '#' && buffer[i - 1] != ' ')
			break;

		if (buffer[i] == '#')
		{
			buffer[i] = '\0';
			break;
		}

		i++;
	}
}
