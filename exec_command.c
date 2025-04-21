#include "shell.h"

/**
 * execute_command - Executes a command with its arguments
 * @argv: Array of command and arguments
 * @progname: Name of the program
 * @cmd_count: Number of commands executed
 * Return: 1 if command was executed, 0 if not
 */
int execute_command(char *argv[], char *progname, int cmd_count)
{
	pid_t pid;
	char *command_path;

	/* Find command in PATH */
	command_path = find_command(argv[0]);
	if (!command_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", progname, cmd_count, argv[0]);
		return (0);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(command_path);
		return (0);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(command_path, argv, environ) == -1)
		{
			perror(argv[0]);
			free(command_path);
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		wait(NULL);
		free(command_path);
	}
	return (1);
}
