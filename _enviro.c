#include "shell.h"

/**
 * handle_env_rep - replaces var with env val
 * @arg: pointer to argument
 * @env: env list header
 * @index: index of $
 * Return: the number of replaced chars
 */
int _env_rep(char **arg, node *env, int index)
{
	int x, count, length;
	char *s = *arg, *var, *tmp, *tmp1;

	for (x = index + 1; s[x] && s[x] != '\n' && s[x] != '$'; x++)
		;
	length = x - index;
	tmp1 = malloc(length + 1);
	for (x = index + 1; s[x] && s[x] != '\n' && s[x] != '$'; x++)
		tmp1[x - index - 1] = s[x];
	tmp1[length - 1] = '\0';
	var = enviro_val(env, tmp1);
	free(tmp1);
	if (!var)
		var = "";
	var = custom_strdup(var);
	tmp = malloc(custom_len(s) + custom_len(var));
	for (x = 0; x < index; x++)
	{
		tmp[x] = s[x];
	}
	for (count = 0; var[count]; count++)
	{
		tmp[x + count] = var[count];
	}
	index += length;
	for (x = x + count; s[index]; x++, index++)
	{
		tmp[x] = s[index];
	}
	tmp[x] = '\0';
	*arg = tmp;
	free(var);
	free(s);

	return (count - 1);
}

/**
 * env_val - gets the value of env
 * @env: env list head
 * @name: name of the env
 * Return: pointer to the value
 */
char *enviro_val(node *env, char *name)
{
	node *tmp = env;
	int x;

	while (tmp)
	{
		if (enviro_comp(tmp->env, name))
		{
			for (x = 0; tmp->env[x]; x++)
			{
				if (tmp->env[x] == '=')
					return (&(tmp->env[x + 1]));
			}
		}
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * set_env - sets the value of env
 * @env: env pointer
 * @name: name of the env
 * @value: value of the env
 * Return: pointer to the value
 */
void s_enviro(node *env, char *value, char *name)
{
	if (!env)
		return;
	free(env->env);
	env->env = _concat(name, value);
}


/**
 * list_arr - builds array from linked list
 * @env: env list head
 * @envs: pointer to pointer to array
 * Return: always 1
 */
int l_array(node *env, char ***envs)
{
	node *tmp = env;
	int x;

	if (*envs)
		free(*envs);

	for (x = 1; tmp; x++)
	{
		tmp = tmp->next;
	}
	*envs = malloc(sizeof(char *) * x);
	for (x = 0, tmp = env; tmp; x++)
	{
		envs[0][x] = tmp->env;
		tmp = tmp->next;
	}
	envs[0][x] = NULL;

	return (1);
}

/**
 * build_env - build linked list env
 * @env: env list
 *
 * Return: poniter to head of the linked list
 */
node *b_enviro(char **env)
{
	int x = 0;
	node *env_head = NULL;

	while (env[x])
	{
		a_node(&env_head, env[x++]);
	}

	return (env_head);
}

/**
 * free_env - free env linked list
 * @env_head: head of struct
 */
void f_enviro(node *env_head)
{
	node *head;
	int x;

	for (x = 0; env_head; x++)
	{
		head = env_head;
		env_head = env_head->next;
		free(head->env);
		free(head);
	}
}

/**
 * print_env - prints linked list
 * @head: pointer to linked list
 * Return: 1 always
 */
int p_enviro(node *head)
{
	node *tmp = head;

	if (!tmp)
		return (0);
	p_enviro(tmp->next);
	write(STDOUT_FILENO, tmp->env, custom_len(tmp->env) - 1);
	write(STDOUT_FILENO, "\n", 1);
	return (1);
}


/**
 * envcmp - fucntion
 * @env: a pointer to env value
 * @s: a pointer to a string
 *
 * Description: compares two strings env and s2
 *
 * Return: 1 if they are the same 0 otherwise
 */

int enviro_comp(char *env, char *s)
{
	int x = 0;

	while (1)
	{
		if (env[x] == '=' && (s[x] == '\0' || s[x] == '='))
			return (1);
		else if (env[x] == '\0')
			return (0);
		else if (env[x] != s[x])
			return (0);
		x++;
	}
	return (0);
}

/**
 * is_env - checks if env contains =
 * @var: value of env
 * Return: 1 if it does 0 if not
 */
int _enviro_(char *var)
{

	int x = 0;

	for (x = 0; var[x]; x++)
	{
		if (var[x] == '=')
			return (1);
	}
	return (0);

}
