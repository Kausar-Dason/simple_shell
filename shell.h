#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ; /* Declare environ */

void c_print(const char *text);
void display_prompt(void);
char *read_input(char **command, size_t *size);
void execute(const char *command);
char *_getenv(const char *name);
char *find_executable(const char *command);
char *construct_full_path(const char *dir, const char *command);



/* custom string functions */
int _strlen(const char *s);
char *_strdup(char *str);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *d, const char *s);
char *_strcat(char *dest, const char *src);

#endif
