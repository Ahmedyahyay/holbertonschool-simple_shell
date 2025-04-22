#include "shell.h"

/**
 * parse_input - Tokenizes the input line
 * @line: Input string
 *
 * Return: Array of arguments (NULL-terminated)
 */
char **parse_input(char *line)
{
	char *token = NULL, **tokens = NULL;
	int bufsize = 64, i = 0;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("realloc");
				return (NULL);
			}
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
