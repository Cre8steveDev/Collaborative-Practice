#include "shell.h"
/**
 * zerror - Prints custom erro message to standard error
 * @prog: Program name
 * @count: Command count
 * @cmd: Command entered by user
 * Author: David Obodo (Cohort 16 - ALX)
 * Return: Void
 *
 */

void zerror(char *prog, int count, char *cmd)
{
	_puts(prog);
	_puts(": ");
	_putchar(count);
	_puts(": ");
	_puts(cmd);
	_puts(": not found\n");
}

/**
 * _puts - prints a given string
 * @str: String to be printed
 * Author: David Obodo (Cohort 16 - ALX)
 * Return: Void
 *
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _putchar - Prints a character to standard error
 * @c: Character to be printed
 * Author: David Obodo (Cohort 16 - ALX)
 * Return: An integer
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}
