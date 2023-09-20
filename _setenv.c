#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv -  Function to change or add an environment variable.
 * @name: constant character
 * @value: constant character
 * @overwrite: looped integer value
 * Return: -1 when updating, -1 when adding, 0 if success
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char *exists;
	char *n_env;

	exists = getenv(name);

	if (exists)
	{
		if (overwrite)
		{
			n_env = (char *)malloc(strlen(name) + strlen(value) + 2);
			if (!n_env)
			{
				return (-1);
			}
			sprintf("%s=%s", n_env, name, value);

			if (putenv(n_env) != 0)
			{
				return (-1);
			}
		}
	}

	else
	{
		if (setenv(name, value, 1) != 0)
		{
			return (-1);
		}
	}
	return (0);
}
