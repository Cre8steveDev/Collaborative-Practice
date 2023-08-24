#include "shell.h"

int handle_builtins(char **args, char *progname, char *buffer)
{
	int executed = 0, idx = 0;

	(void)progname;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buffer);
		exit(errno);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[idx] != NULL)
		{
			write(1, environ[idx], strlen(environ[idx]));
			write(1, "\n", 1);

			idx++;
		}
		free(args); /*There is no need to free the buffer at this point since getline -1 frees it already*/
		executed = 1;
	}

	return (executed);
}
