#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

/**
 * struct list - struct
 * @env: evirument value
 * @next: pointer to next node
 */
typedef struct list
{
	char *env;
	struct list *next;
} node;

/**
 * struct all - struct
 * @envs: pointer to env array
 * @args: pointer to array of pointers of args
 * @env: pointer to head of env list
 * @count: the number that the
 * @s: the string that stores input
 * @status: last exit stat
 * @seq: seq of comands
 * @ali: array of alias
 * @name: name of the file
 * @com: name of the comand
 * @input: input in non-interactive mod
 * @fd: file descreptor if any
 */
typedef struct all
{
	char **envs;
	char ***args;
	node *env;
	int count;
	char *s;
	int status;
	char seq[10];
	char **ali;
	char *name;
	char *com;
	char *input;
	int fd;
} all_t;



/** function for different modes */
void inter_mode(all_t *a);
void non_inter_mode(all_t *a);
void argument_loop(all_t *a);
char *_path_(char *PATH, char *s);
int _getline_(char **s, int *l, int stream);


/** function for environment variables */
void f_enviro(node *env_head);
node *b_enviro(char **env);
int enviro_comp(char *env, char *s);
int _enviro_(char *var);
int p_enviro(node *env);
int a_node(node **head, char *env_value);
char *enviro_val(node *env, char *name);
node *g_node(node *env, char *name);
void s_enviro(node *env, char *value, char *name);
int l_array(node *env, char ***envs);


/** cd functions */
int change_dir(char *dir, all_t *a);
void change_dir_err(char *dir, all_t *a);


/** alias.c */
int alias(node **env, char **arg, char ***ali);
char *alias_value(char **ali, char *name);
int put_alias(char *new_ali, char ***ali);
char *g_alias(char *name, char **ali);
int free_array(char **ar);
char *b_alias(char *ali, char *val);
void p_alias(char *ali);


/** strtok funtions */
char ***_strtok(char *s, char seq[10]);
char *_strtok1(char *s, int *k, char dilm);
char *get_next_arg(char *s, int *k);
int *arg_num(char *s, char seq[10]);
int free_arg(char ***ar);


/**  built in functions */
int _setenv(node **env, char *name, char *value);
int _unsetenv(char *env_name, node **env);
int built_exit(char **arg, all_t *a);
int _exit_(char *code, all_t *a);


/** errors.c */
void com_error(char *name, int n, char *com);
void f_error(all_t *a, char *file);


/** var  functions */
void _variable(char **arg, node *env, char **ali, int n);
int _pid_rep(char **arg, int index);
int _exit_rep(char **arg, int n, int index);
int _env_rep(char **arg, node *env, int index);


/** custom functions */
int _empty(char *s);
char *_concat(char *s1, char *s2);
char *custom_strdup(char *str);
int custom_len(char *s);
int custom_strcmp(char *s1, char *s2);
void n_string(int n, char *s);
int count_word(char *s);
char *custom_memcpy(char *dest, char *src, unsigned int n);
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _free(all_t *a);



#endif 
