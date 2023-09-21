#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
/** functions for environent */
int shell_prompt(char *av[], int counter_exe, char **env);
int env_command(char *av[], int counter_exe, char **env);
char *name_file(char *full_path, char *file_name);
void _getenv(char **env);

/** functions for custom string functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_setenv(char *name, char **env);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);

/** functions for memory allocation */
char *mem_set(char *s, char a, unsigned int n);
void *mem_alloc(unsigned int memn, int size);

#endif

<<<<<<< HEAD
=======
extern char **environ;

/** Macros for aliases */
#define ALIASES 50
#define ALIAS_NAME_LEN 50
#define ALIAS_VALUE_LEN 200

/* buffer size*/
#define BUFFER_SIZE 64

/** Macro for cd */
#define CD_LENGTH 1024

/** Macro for main function */
#define INPUT_LENGTH 1024

/** Macro for shell prompt */
#define INPUT_SIZE 256

/** struc to store aliases */
struct Alias {
    char name[ALIAS_NAME_LEN];
    char value[ALIAS_VALUE_LEN];
};

/** array to store aliases */
struct Alias aliases[ALIASES];

/** shell prompt function */

void shell_prompt(char *command);

/* environment functions (enviro.c) */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
<<<<<<< HEAD

/* function to send formatted output to the screen.*/
void _fork(char *buffer);
void shell();
char *input_getline();
char s_print(char *argv);
char *token_strtok(char *input);

/* function for variables */
=======
>>>>>>> 831b457256a0def879e70f0fff2d3c0046ca7efd
void variables(char *command);

/* function for alias */
void write_aliases(char *string);
void aliases_print();
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
>>>>>>> 4b7795b8f9da43b6750581b6a46872b481ea8b7e
