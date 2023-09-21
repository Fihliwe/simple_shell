#include "shell.h"

/**
 * get_path - checks if the command is in path
 *
 * @PATH: path from env
 * @s: command as string
 *
 * Return: the full path of command or NULL
 */
char *_path_(char *PATH, char *s)
{
	char *path, *tmp, *token, *tmp1;
	struct stat st;
	int k = 0;

	if (stat(s, &st) == 0 && (s[0] == '.' || s[0] == '/'))
		return (s);

	if (!PATH)
	{
		free(s);
		return (NULL);
	}
	path = custom_strdup(PATH);
	tmp1 = _concat("/", s);
	free(s);
	s = tmp1;
	while (path[k] && path[k] != '\n')
	{
		token = _strtok1(path, &k, ':');
		if (token[custom_len(token) - 2] == '/')
			tmp = _concat(token, &s[1]);
		else
			tmp = _concat(token, s);
		if (stat(tmp, &st) == 0)
		{
			free(path);
			free(s);
			free(token);
			return (tmp);
		}
		free(tmp);
		free(token);
	}
	free(path);
	free(s);
	return (NULL);
}
