#include "shell.h"

/**
 * _setenv - set a new env
 *
 * @env: pointer to the head of struct
 * @name: name of env
 * @value: value of env
 *
 * Return: always 1
 */
int _setenv(node **env, char *name, char *value)
{
	node *tmp = *env;
	char *string, *string1;

	if (!name || _enviro_(name) || !value)
	{
		return (0);
	}

	string = _concat(name, "=");
	string1 = _concat(string, value);
	free(string);
	while (tmp)
	{
		if (enviro_comp(tmp->env, name))
		{
			free(tmp->env);
			tmp->env = string1;
			return (1);
		}
		tmp = tmp->next;
	}
	a_node(env, string1);
	free(string1);
	return (1);
}
