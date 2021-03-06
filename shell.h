#ifndef SHELL_H
#define SHELL_H

extern char **environ;
extern char *program_invocation_name;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
int _printenv(char **args);
int _cd(char **args);

/*String Function*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *dest, const char *src);
char *_strdup(char *s);
char *_strcat(char *str1, char *str2);
char *_memset(char *s, char b, unsigned int n);
int _atoi(char *s);

/*Print functions*/
void printint(int n);
void _puts(char *s);
int _putchar(const char c);

/*helper functions*/
char **split_line(char *line, char *delim);
char **re_alloc(char **ptr, int *size);
int pr_exec(char **args, builtins_t *builtin);
char *_getenv(char *name);
char *read_line(void);
void ctrlC(int sig_num);
char *_strtok(char *str, char *delim);
int *create_delim_dict(char *delim);
void format_error(int *status, int count_err, char **args);
void no_inter(builtins_t *builtin);
ssize_t _getline(char **lineptr);

#endif
