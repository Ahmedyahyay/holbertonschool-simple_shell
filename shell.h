#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* External environment variable */
extern char **environ;

/* Constants */
#define MAX_LINE 1024
#define MAX_ARGS 64
#define MAX_PATH_LEN 1024

/* Function declarations from shell_helpers.c */
char *_getenv(const char *name);
char *find_command(char *command);
void print_env(void);
int parse_input(char *line, char *argv[]);
int handle_builtins(char *argv[]);

/* Function declarations from shell.c */
int execute_command(char *argv[], char *progname, int cmd_count);

#endif /* SHELL_H */
