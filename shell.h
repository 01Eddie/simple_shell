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

char **split_line(char *line, char *delim);
char **re_alloc(char **ptr, int *size);

/*String Function*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int strcmp(const char *dest, const char *src);
char *_strdup(char *s);
char *_strcat(char *str1, char *str2);
char **split_line(char *line, char *delim);
char **re_alloc(char **ptr, int *size);
int pr_exec(char **args);
char *_getenv(char *name);
char *read_line(void);

#endif
