#include "shell.h"

/**
 * _setenv - variable enviriomment to be gotten
 * @name: name the variable envirionment
 * @env: environment variable
 * Return: char value envirionment
 **/

char *_setenv(char *name, char **env)
{
	char *tok1 = NULL, *tok2 = NULL;
	char *enviro_name = NULL, *curr_enviro = NULL;
	int i = 0;

	enviro_name = _strdup(name);

	while (env[i] && env)
	{
		curr_enviro = NULL;
		tok2 = NULL;
		curr_enviro = _strdup(env[i]);
		tok1 = strtok(curr_enviro, "=");
		tok2 = _strdup(strtok(NULL, "="));
		if (_strcmp(enviro_name, tok1) == 0)
		{
			free(curr_enviro);
			free(enviro_name);
			return (tok2);
		}
		free(curr_enviro);
		free(tok2);
		i++;
	}
	free(enviro_name);
	return (NULL);
}
