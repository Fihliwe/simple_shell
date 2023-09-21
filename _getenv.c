#include "shell.h"

/**
 * _getenv - print variable global envirionment
 * @env: variable global envirionment system
 * Return: estatus_exit value;
 **/

void _getenv(char **env)
{
	int x = 0;

	while (env[x] != NULL)
	{
		write(STDOUT_FILENO, env[x], strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
