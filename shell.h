#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/* environment functions (enviro.c) */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* function for variables */

/* function for alias */

/* function for logical operators */

/* function for commands seperator */

/* function for builtin command (cd - change directory) */

#endif/* SHELL_H*/
