#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _unsetenv - deletes environment variable
 * @name: constant character
 * Return: -1 if invalid, 0 if succes or not found
 */

int _unsetenv(const char *name)
{
	int x;
	int y;
	size_t len;

	len = strlen(name);

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		return (-1);
	}

	for (x = 0; environ[x] != NULL; x++)
	{
		if (strncmp(environ[x], name, len) == 0 && environ[x][len] == '=')
		{
			for (y = x; environ[y] != NULL; y++)
			{
				environ[y] = environ[y + 1];
			}
			return (0);
		}
	}

	return (0);
}
