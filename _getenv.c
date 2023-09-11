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
	char **nviro;

	len = strlen(name);

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}

	for (nviro = environ; *nviro != NULL; nviro++)
	{
		if (strncmp(*nviro, name, len) == 0 && (*nviro)[len] == '=')
		{
			return (*env + len + 1);
		}
	}

	return (NULL);
}
