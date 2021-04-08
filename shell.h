#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Structs */
/**
 * struct builtins - struct to handle the built-ins commands
 * @command: command inputed
 * @func: function pointer to execute the command
 *
 */
typedef struct builtins
{
	char *command;
	int (*func)(char **argv);
} builtins_t;

/*Built-in functions*/
int new_exit(char **args);

/*String Function*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *dest, const char *src);
char *_strdup(char *s);
char *_strcat(char *str1, char *str2);

char **split_line(char *line, char *delim);
char **re_alloc(char **ptr, int *size);
int pr_exec(char **args, builtins_t *builtin);
char *_getenv(char *name);
char *read_line(void);
void ctrlC(int sig_num);

#endif
