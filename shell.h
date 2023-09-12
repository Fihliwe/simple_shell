#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/** buffers for aliases */
#define ALIASES 50
#define ALIAS_NAME_LEN 50
#define ALIAS_VALUE_LEN 200

/** struc to store aliases */
struct Alias {
    char name[ALIAS_NAME_LEN];
    char value[ALIAS_VALUE_LEN];
};

/** array to store aliases */
struct Alias aliases[MAX_ALIASES];
int aliasCount = 0;


/* environment functions (enviro.c) */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* function for variables */
void variables(char *command);
/* function for alias */

/* function for logical operators */

/* function for commands seperator */

/* function for builtin command (cd - change directory) */

#endif/* SHELL_H*/
