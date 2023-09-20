#include "main.h"

/**
 * _path - function for path.
 * @instruction: character string.
 * @Return: 0 if path not found.
 */

int _path(const char *instruction)
{
	int x;
	int y;
	char *path;
	char *copy_path;
	char *tok;
	char path_full[256];

	x = 0;
	y = 0;
	path = getenv("PATH");
	copy_path = strdup(path);
	tok = strtok(copy_path, ":");

	while (token != NULL)
	{
		while (tok[x] != '\0' && x < sizeof(path_full) - 2)
		{
			pathfull[x] = tok[x];
			x++;
		}

		path_full[x] = '/';
		x++;

		while (instruction[y] != '\0' && x < sizeof(path_full) - 1)
		{
			path_full[x] = instruction[y];
			x++;
			y++;
		}

		path_full = '\0';

		if (access(path_full, F_OK) == 0)
		{
			free(copy_path);
			return (-1);
		}

		tok = strtok(NULL, ":");
	}
	free(copy_path);
	return (0);
}
