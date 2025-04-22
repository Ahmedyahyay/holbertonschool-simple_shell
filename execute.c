#include "shell.h"
extern char **environ;

/**
 * execute - Forks and executes the command
 * @args: Command and arguments
 * @program_name: The name of the executable (argv[0])
 *
 * Return: 1 to continue, 0 to exit
 */
int execute(char **args, char *program_name)
{
	pid_t pid;
	int status;
	char *cmd = args[0];
	struct stat st;

	if (cmd == NULL)
		return (1);

	if (strcmp(cmd, "exit") == 0)
		return (0);

	if (stat(cmd, &st) != 0)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, cmd);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}
