#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
extern char **environ;
char *getln(void);
char **formatln(char *ln);
char *compose(char *token, char *val);
int launch_process(char **command);
void search_exe(char **command);
char *_getenv(char *name);
void handler_function(int i);
#endif
