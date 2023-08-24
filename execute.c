#include "shell.h"

/**
 * execn - Executes the command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * Author: Oluwatobi Adesanya (Cohort 16 - ALX SE)
 * Return: Void
 */

int execn(char **args, char **argv)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		errno = status;

		/*A Macro that handles correct conversion of exit status of the child*/
		free(args); /*This was a dynamically allocated array of strings*/
	}

	return (status);
}
