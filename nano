#include "shell.h"

/**
 * handle_builtins - Handles built-in commands
 * @argv: Array of command and arguments
 * Return: 1 if built-in was handled, 0 if not
 */
int handle_builtins(char *argv[])
{
	if (strcmp(argv[0], "exit") == 0)
		return (2); /* Special return value for exit */
	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}
