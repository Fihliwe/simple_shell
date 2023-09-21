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

