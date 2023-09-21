#include "shell.h"

/**
 * cd - changes directory
 *
 * @dir: directory to move to
 * @a: pointer to all struct
 *
 * Return: 1 on success 0 otherwise
 */
int change_dir(char *dir, all_t *a)
{
	int status = 0;
	char *path = NULL, *buff = NULL;
	node *pwd = g_node(a->env, "PWD");
	node *opwd = g_node(a->env, "OLDPWD");

	if (!dir)
	{
		path = enviro_val(a->env, "HOME");
		if (path != NULL)
			status = chdir(path);
	}
	else if (custom_strcmp(dir, "-") == 0)
	{
		path = enviro_val(a->env, "OLDPWD");
		if (path != NULL)
			status = chdir(path);
		else
			path = enviro_val(a->env, "PWD");
		write(STDOUT_FILENO, path, custom_len(path) - 1);
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		status = chdir(dir);
	if (status)
	{
		change_dir_err(dir, a);
		return (1);
	}
	path = getcwd(buff, 0);
	if (!path)
	{
		free(buff);
		return (1);
	}
	s_enviro(opwd, enviro_val(a->env, "PWD"), "OLDPWD=");
	s_enviro(pwd, path, "PWD=");
	free(buff);
	free(path);
	return (1);
}


/**
 * cd_error - prints cd errors
 *
 * @dir: name of directory
 * @a: pointer to all struct
 */
void change_dir_err(char *dir, all_t *a)
{
	char s[1024], *num, *err = "cd: can't cd to ";
	int l;

	custom_memcpy(s, a->name, custom_len(a->name) - 1);
	custom_memcpy(&s[custom_len(a->name) - 1], ": ", 2);
	num = malloc(10);
	n_string(a->count, num);
	custom_memcpy(&s[custom_len(a->name) + 1], num, custom_len(num) - 1);
	l = custom_len(a->name) + 1 + custom_len(num) + 2;
	custom_memcpy(&s[l - 3], ": ", 2);
	custom_memcpy(&s[l - 1], err, custom_len(err) - 1);
	custom_memcpy(&s[l + custom_len(err) - 2], dir, custom_len(dir) - 1);
	custom_memcpy(&s[l + custom_len(err) + custom_len(dir) - 3], "\n", 2);
	write(STDERR_FILENO, s, custom_len(s) - 1);
	fflush(stderr);
	free(num);
	a->status = 0;

}
