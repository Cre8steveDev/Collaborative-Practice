#include "shell.h"

/**
 * main - Simple shell entry point
 * @argc: Argument counter
 * @argv: Argument Vector
 * Return: Errno
 *
 */

int main(int argc, char **argv)
{

	int mode = isatty(0);
	char *buffer = NULL, cmdc, **args = NULL, *fullcmd = NULL;
	size_t buff_Size = 0;
	ssize_t num = 0;
	int count = 0, builtin_status = 0;
	errno = 0;

	(void)argc;
	while (1)
	{
		count++;
		if (mode == 1) /*Prints prompt in interactive mode*/
			write(1, "$ ", 2);

		num = getline(&buffer, &buff_Size, stdin);
		if (num == -1)
		{
			/*	if (mode == 1)
					free(args);*/
			/* This was probably unecessary - NO memory leaks*/
			free(buffer);
			exit(errno);
		}
		fix_comments(buffer);
		args = tokenizah(buffer); /*dynamically allocated*/
		if (args[0] == NULL)
		{
			free(args); /*When ONLY SPACES OR NEW LINES ARE ENTERED We return and print the prompt*/
			continue;
		}
		/*Tests that the command is wrong - NOT A FULL PATH!*/
		/* Access returns -1 when the path is not found*/
		if (access(args[0], X_OK) == -1)
		{
			/*Confirm if it's a builtin: If it returns 0 it means cmd is not a builtin else it returns 1 to builtin_status*/
			builtin_status = handle_builtins(args, argv[0], buffer);

			if (builtin_status == 1)
				continue;

			/*Get full path and assign to fullpath variable*/ /* Implement builtin within this block*/
			fullcmd = get_full_path(_getpath(), args[0]);

			if (fullcmd == NULL)
			{
				cmdc = (count + '0'); /*Converting an int to char*/
				zerror(argv[0], cmdc, args[0]);
				free(args);
				errno = 127; /*Sets errno to 127 for cmd not found - since no system call is made here*/
				continue;
			}
			/* This is only called when the concatenated full path is valid i.e full path not NULL*/
			extra_execn(args, argv, fullcmd);
			continue;
			/*Continuing to the top of the loop so the execute underneath is not called*/
		}
		/* Handles when full path is entered by user correctly*/
		execn(args, argv);
	}

	return (errno);
}
