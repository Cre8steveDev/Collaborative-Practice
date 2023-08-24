#include "shell.h"

/**
 * get_full_path - returns a valid path else NULL
 * @paths: A string of multiple directories in the path
 * @cmd: Command string (Not an array)
 * Return: A Pointer to full string or NULL
 */

char *get_full_path(char *paths, char *cmd)
{
	char **path_tokens = NULL, *token = NULL, *temp = NULL, *fullpath = NULL;
	int idx = 0;
	size_t len = 0;

	if (paths == NULL)
		return (NULL);

	temp = strtok(paths, "=");
	temp = strtok(NULL, "=");

	path_tokens = malloc(sizeof(char *) * 30);
	if (path_tokens == NULL)
	{
		free(paths);
		return (NULL);
	}

	token = strtok(temp, ":");
	while (token != NULL)
	{
		path_tokens[idx] = token;
		token = strtok(NULL, ":");
		idx++;
	}
	path_tokens[idx] = NULL; /*ARRAY OF ALL DIRECTORIES*/
	idx = 0;

	while (path_tokens[idx] != NULL)
	{
		len = strlen(path_tokens[idx]) + strlen(cmd) + 2;
		fullpath = malloc(len);
		strcpy(fullpath, path_tokens[idx]);
		strcat(fullpath, "/");
		strcat(fullpath, cmd);

		if (access(fullpath, X_OK) == 0)
		{
			free(path_tokens);
			free(paths);
			return (fullpath);
		}
		free(fullpath);
		fullpath = NULL;
		idx++;
	}

	free(path_tokens);
	free(paths);
	return (NULL);
}
