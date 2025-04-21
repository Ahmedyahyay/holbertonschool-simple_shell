#include "main.h"
/**
 * main - execution
 * Return: 0
 */
int main(void)
{

	char *ln, **command;
	int st = 1;

	signal(SIGINT, handler_function);
	do

	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		else
		{
			ln = getln();
			command = formatln(ln);
			search_exe(command);
			launch_process(command);
			free(ln);
			free(command);
			return (0);
		}

		ln = getln();
		command = formatln(ln);
		if (*command == NULL)
		{
			free(ln);
			free(command);
			continue;
		}
		search_exe(command);
		st = launch_process(command);
		free(ln);
		free(command);

	} while (st);

	return (0);
}

/**
 * launch_process - execute command
 * @command: command
 * Return: 1
 */
int launch_process(char **command)
{
	pid_t pid;

	pid = fork();
	if (pid == 0 && execve(command[0], command, environ) == -1)
		perror("./shell");

	else
		wait(&pid);

	return (1);
}
/**
 * handler_function - handle signit
 * @i: integer
 */
void handler_function(int i)
{
	if (i)
	{
		write(STDOUT_FILENO, "\n$ ", strlen("\n$ "));
	}
}
