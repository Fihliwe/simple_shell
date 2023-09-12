#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * _getenv -  function that gets an environment variable
 * @name: constant character
 * Return: NULL
 */

char *_getenv(const char *name)
{
	size_t len;
	char **env;

	len = strlen(name);

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}

	return (NULL);
}
