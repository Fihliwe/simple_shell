#include "shell.h"

/**
 * handle_exit_rep - replaces var with exit value
 * @arg: pointer to argument
 * @n: last exit value
 * @index: index of $
 * Return: the number of replaced chars
 */
int _exit_rep(char **arg, int n, int index)
{
	int x, count;
	char *string = *arg, *num, *tmp;

	num = malloc(n / 10 + 2);
	tmp = malloc(custom_len(string) + n / 10);
	n_string(n, num);

	for (x = 0; x < index; x++)
	{
		tmp[x] = string[x];
	}
	for (count = 0; num[count]; count++)
	{
		tmp[x + count] = num[count];
	}
	index += 2;
	for (x = x + count; string[index]; x++, index++)
	{
		tmp[x] = string[index];
	}
	tmp[x] = '\0';
	*arg = tmp;
	free(num);
	free(string);

	return (count - 2);
}

/**
 * built_in - ex built in fun
 *
 * @arg: commands and their args
 * @a: pointer to all struct
 *
 * Return: 1 if built in 0 otherwise
 */
int built_exit(char **arg, all_t *a)
{
	_variable(arg, a->env, a->ali, a->status);
	if (!arg[0])
		return (1);
	if (custom_strcmp(arg[0], "exit") == 0)
	{
		_exit_(arg[1], a);
		return (1);
	}
	if (custom_strcmp(arg[0], "env") == 0 && p_enviro(a->env))
		return (1);
	if (custom_strcmp(arg[0], "cd") == 0 && change_dir(arg[1], a))
		return (1);
	if (custom_strcmp(arg[0], "alias") == 0 && alias(&a->env, &arg[1], &a->ali))
		return (1);
	if (custom_strcmp(arg[0], "setenv") == 0)
	{
		if (arg[1] && arg[2])
			_setenv(&a->env, arg[1], arg[2]);
		return (1);
	}
	else if (custom_strcmp(arg[0], "unsetenv") == 0 && _unsetenv(arg[1], &a->env))
		return (1);

	return (0);
}

/**
 * exit_with - exits with code
 *
 * @code: exit value (NULL = 0)
 * @a: pointer to all struct
 * Return: exit val or -1
 *
 */
int _exit_(char *code, all_t *a)
{
	int sum = 0, x, length;
	char s[1024], *exi = "exit: Illegal number: ", *num;

	if (code == NULL)
	{
		_free(a);
		exit(a->status);
	}
	for (x = 0; code[x]; x++)
	{
		if (code[x] < '0' || code[x] > '9')
		{
			custom_memcpy(s, a->name, custom_len(a->name) - 1);
			custom_memcpy(&s[custom_len(a->name) - 1], ": ", 2);
			num = malloc(10);
			n_string(a->count, num);
			custom_memcpy(&s[custom_len(a->name) + 1], num, custom_len(num) - 1);
			length = custom_len(a->name) + 1 + custom_len(num) + 2;
			custom_memcpy(&s[length - 3], ": ", 2);
			custom_memcpy(&s[length - 1], exi, custom_len(exi) - 1);
			custom_memcpy(&s[length + custom_len(exi) - 2], code, custom_len(code) - 1);
			custom_memcpy(&s[length + custom_len(exi) + custom_len(code) - 3], "\n", 2);
			write(STDERR_FILENO, s, custom_len(s) - 1);
			fflush(stderr);
			free(num);
			a->status = 2;
			return (-1);
		}
		sum = sum * 10 + code[x] - '0';
	}
	_free(a);
	exit(sum % 256);
}
