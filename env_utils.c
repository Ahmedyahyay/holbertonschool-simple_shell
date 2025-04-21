#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment variable
 * Return: Value of the environment variable or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}
