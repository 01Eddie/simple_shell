#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdlib.h>

char **split_line(char *line, char *delim);
char **re_alloc(char **ptr, int *size);

/*String Function*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int strcmp(const char *dest, const char *src);
char *_strdup(char *s);
#endif
