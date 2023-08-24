#include "shell.h"

/**
 * extra_execn - Executes the command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * @fullcmd: Full command
 * Author: Oluwatobi Adesanya
 * Return: Void
 */

int extra_execn(char **args, char **argv, char *fullcmd)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(fullcmd);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(fullcmd, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		/*A Macro that handles correct conversion of exit status of the child*/
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		errno = status;

		free(fullcmd);
		free(args);
	}
	return (status);
}
