#include "shell.h"

/**
 * _unsetenv - removes env
 *
 * @env_name: env name to remove
 * @env: head of env list
 *
 * Return: 1 on succes 0 otherwise
 */
int _unsetenv(char *env_name, node **env)
{
	node *tmp = *env, *tmp1 = tmp;

	if (!env_name)
	{
		return (1);
	}

	if (enviro_comp(tmp->env, env_name))
	{
		*env = tmp->next;
		free(tmp->env);
		free(tmp);
		return (1);
	}

	while (tmp)
	{
		if (enviro_comp(tmp->env, env_name))
		{
			free(tmp->env);
			tmp1->next = tmp->next;
			free(tmp);
			return (1);
		}
		tmp1 = tmp;
		tmp = tmp->next;
	}
	return (1);
}
