#include "shell.h"

/**
 * tokenizah - Tokenizes a string and returns
 * a dynamically allocated array of strings
 * @string: Buffer entered by user
 * Return: Double pointer of the string
 */

char **tokenizah(char *string)
{
	char **tokens = NULL;
	int x = 0;
	char *token = NULL, *delimiter = " \n";

	tokens = malloc(sizeof(char *) * 25);
	if (tokens == NULL)
		return (NULL);

	token = strtok(string, delimiter);

	while (token != NULL)
	{
		tokens[x] = token;
		token = strtok(NULL, delimiter);
		x++;
	}

	tokens[x] = NULL;
	return (tokens);
}
