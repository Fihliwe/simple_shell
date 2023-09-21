#include "shell.h"

/**
 * alias - sets or prints alias
 *
 * @env: env list header
 * @arg: directory to migrate to
 * @ali: list of all allias
 *
 * Return: 1 on success 0 otherwise
 */
int alias(node **env, char **arg, char ***ali)
{
	int x;
	char *alis;

	if (!arg[0] && *env)
	{
		if (!ali[0])
		{
			printf("NO ALIAS YET\n");
			return (1);
		}
		for (x = 0; ali[0][x]; x++)
		{
			p_alias(ali[0][x]);
		}
	}
	for (x = 0; arg[x]; x++)
	{
		if (_enviro_(arg[x]))
		{
			put_alias(arg[x], ali);
		}
		else
		{
			alis = g_alias(arg[x], ali[0]);
			if (!alis)
				return (1);
			p_alias(alis);
		}
	}
	return (1);
}


/**
 * ali_val - gets the alias of env
 * @ali: env list head
 * @name: name of the env
 * Return: pointer to the value
 */
char *alias_value(char **ali, char *name)
{
	int x, y;

	if (!ali)
		return (NULL);
	for (y = 0; name[y] != '=' && name[y]; y++)
		;
	if (!name[y])
	{
		for (x = 0; ali[x]; x++)
		{
			if (enviro_comp(ali[x], name))
			{
				for (y = 0; ali[x][y] != '='; y++)
					;
				return (&ali[x][y + 1]);
			}
		}
		return (NULL);
	}
	for (x = 0; ali[x]; x++)
	{
		if (enviro_comp(ali[x], &name[y + 1]))
		{
			return (&name[y + 1]);
		}
	}
	return (NULL);
}


/**
 * put_alias - adds a new alias
 * @new_ali: alias to add
 * @ali: array of aliases
 * Return: always 1
 */
int put_alias(char *new_ali, char ***ali)
{
	int x, y, z = sizeof(char *);
	char *tmp, *s;

	if (!(*ali))
	{
		*ali = malloc(z * 2);
		ali[0][0] = custom_strdup(new_ali);
		ali[0][1] = NULL;
	}
	else
	{
		for (x = 0; ali[0][x]; x++)
		{
			if (enviro_comp(ali[0][x], new_ali))
			{
				free(ali[0][x]);
				ali[0][x] = custom_strdup(new_ali);
				return (1);
			}
		}
		ali[0] = custom_realloc(ali[0], z * (x + 1), z * (x + 2));
		ali[0][x] = custom_strdup(new_ali);
		ali[0][x + 1] = NULL;
		tmp = alias_value(*ali, new_ali);
		if (tmp == NULL)
			return (1);
		for (y = 0; ali[0][y]; y++)
		{
			if (x != y && enviro_comp(ali[0][y], tmp))
			{
				for (z = 0; ali[0][y][z] != '='; z++)
					;
				tmp = &ali[0][y][z + 1];
				s = b_alias(ali[0][x], tmp);
				free(ali[0][x]);
				ali[0][x] = s;
			}
		}
	}
	return (1);
}


/**
 * get_alias - get the alias
 * @name: name of alias
 * @ali: array of aliases
 * Return: pointer to alias or NULL
 */
char *g_alias(char *name, char **ali)
{
	int x = 0;

	if (!ali)
		return (NULL);
	while (ali[x])
	{
		if (enviro_comp(ali[x], name))
			return (ali[x]);
		x++;
	}
	return (NULL);
}


/**
 * free_arr - frees array
 * @ar: pointer to array
 * Return: always 1
 */
int free_array(char **ar)
{
	int x;

	if (!ar)
		return (1);
	for (x = 0; ar[x]; x++)
	{
		free(ar[x]);
	}
	free(ar);
	return (1);
}
