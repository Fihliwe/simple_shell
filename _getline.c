#include "shell.h"

/**
 * _getline - read from stream
 *
 * @s: pointer to string
 * @l: pointer to int to store the allocated memory
 * @stream: fd of reading source
 *
 * Return: Number of read chars or -1
 */
int _getline_(char **s, int *l, int stream)
{
	static int size = 120;
	int stat;

	*s = malloc(size);
	*l = size;
	while (1)
	{
		stat = read(stream, &(*s)[*l - size], size);
		if (stat == size)
		{
			*l += size;
			*s = custom_realloc(*s, *l - size, *l);
		}
		else if (stat == -1 || stat == 0)
		{
			return (stat);
		}
		else
		{
			(*s)[stat + *l - size - 1] = '\0';
			return (*l - size + stat);
		}
	}
}
