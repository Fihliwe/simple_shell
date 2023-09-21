#include "shell.h"


/**
 * var - switches the args to var if any
 * @arg: list of args
 * @env: head of env list
 * @ali: alias array
 * @n: the number of comands till now
 */
void _variable(char **arg, node *env, char **ali, int n)
{
	int x, y;
	char *tmp, *string;

	if (!arg[0])
		return;
	tmp = alias_value(ali, arg[0]);
	if (tmp)
	{
		tmp = custom_strdup(tmp);
		free(arg[0]);
		arg[0] = tmp;
	}
	else if (arg[0][0] == '$')
	{
		if (_env_rep(&arg[0], env, 0) <= 0)
		{
			free(arg[0]);
			arg[0] = arg[1], arg[1] = NULL;
		}
	}
	for (x = 1; arg[x]; x++)
	{
		for (y = 0; arg[x][y]; y++)
		{
			string = &arg[x][y];
			if (*string == '$' && string[1] && string[1] != '\n' && string[1] != ' ')
			{
				if (arg[x][y + 1] == '$')
					y += _pid_rep(&arg[x], y);
				else if (arg[x][y + 1] == '?')
					y += _exit_rep(&arg[x], n, y);
				else
					y += _env_rep(&arg[x], env, y);
			}
		}
	}
}
