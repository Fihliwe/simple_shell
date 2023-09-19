#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/** Macros for aliases */
#define ALIASES 50
#define ALIAS_NAME_LEN 50
#define ALIAS_VALUE_LEN 200

/** Macro for cd */
#define CD_LENGTH 1024

/** struc to store aliases */
struct Alias {
    char name[ALIAS_NAME_LEN];
    char value[ALIAS_VALUE_LEN];
};

/** array to store aliases */
struct Alias aliases[ALIASES];
int aliasCount = 0;


/* environment functions (enviro.c) */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* function for variables */
void variables(char *command);

/* function for alias */
void writeAliases(char *string);
void aliasesPrint();
void specific_aliases(char *alias_name[], int alias_name_count);
void update_aliases(char *value, char *name);

/* function for logical operators */
void logic_op(char *command);

/* function for commands seperator */
int command_sep(char *command);

/* function for builtin command (cd - change directory) */
int change_dir(const char *change);

/** Function for exit function */
void _exit(int stat);

#endif/* SHELL_H*/
