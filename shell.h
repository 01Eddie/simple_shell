#ifndef SHELL_H
#define SHELL_H

char **split_line(char *line, char *delim);
char **re_alloc(char **ptr, int *size);

#endif
