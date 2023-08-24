#include "shell.h"

/**
 * free_array - Frees an array of dynamically allocated string
 * @argc: Number to be freed
 * @argv: Array of dynamically allocated strings
 * Author: Wassim Haimoudi
 * Return: Void
 */

void free_array(int argc, char *argv[])
{
	int i = 0;

	if (argv)
	{
		for (; i < argc; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
}
