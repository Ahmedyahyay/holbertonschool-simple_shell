#include "shell.h"

/**
 * parse_input - Parses the input line into command and arguments
 * @line: Input line to parse
 * @argv: Array to store parsed arguments
 * Return: Number of arguments parsed
 */
int parse_input(char *line, char *argv[])
{
	int argc = 0;

	argv[argc] = strtok(line, " \t");
	while (argv[argc] != NULL && argc < MAX_ARGS - 1)
	{
		argc++;
		argv[argc] = strtok(NULL, " \t");
	}
	argv[argc] = NULL;
	return (argc);
}
