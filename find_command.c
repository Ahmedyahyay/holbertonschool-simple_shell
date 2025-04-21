#include "shell.h"

/**
 * find_command - Finds the full path of a command
 * @command: Command to find
 * Return: Full path of the command or NULL if not found
 */
char *find_command(char *command)
{
	char *path, *path_copy, *dir, *full_path;

	if (strchr(command, '/')) /* If cmd have '/', chck if it exists and is exe */
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = _getenv("PATH"); /* Get PATH environment variable */
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
