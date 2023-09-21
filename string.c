#include "shell.h"

/**
 * n_string - converts n to string
 *
 * @n: number to convert
 * @s: string to store in
 */
void n_string(int n, char *s)
{
	int x, tmp = n, l = 0;

	while (tmp / 10 != 0)
	{
		tmp /= 10;
		l++;
	}

	s[l + 1] = '\0';

	for (x = l ; x >= 0; x--)
	{
		s[x] = n % 10 + '0';
		n /= 10;
	}
}

/**
 * count_word - counts the number of words
 *
 * @s: string
 *
 * Return: the number of words
 */
int count_word(char *s)
{
	int x, count = 0, start;

	start = s[0] == ' ' ? 1 : 0;

	for (x = 0; s[x] && s[x] != '\n'; x++)
	{
		if (start && s[x] != ' ')
		{
			count++;
			start = 0;
		}
		else if (s[x] != ' ' && (s[x + 1] == ' ' || s[x + 1] == '\n'
			|| s[x + 1] == '\0'))
		{
			count++;
		}
	}

	return (count);
}

/**
 * custom_realloc -  resizes ptr to the new size
 * @ptr: first number
 * @old_size: the size of ptr
 * @new_size: the new specified size
 *
 *
 * Return: a pointer to the array or Null if new_size = 0 and ptr != null
 * or failed to allocate memory or ptr if old = new size
 */

void *custom_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *new_pointer;
	unsigned int l = o_size < n_size ? o_size : n_size;

	if (o_size == n_size)
	{
		return (ptr);
	}
	else if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		new_pointer = malloc(n_size);
		if (new_pointer)
		{
			free(ptr);
			return (new_pointer);
		}
		else
			return (NULL);
	}


	new_pointer = malloc(n_size);
	if (new_pointer == NULL)
		return (NULL);

	custom_memcpy(new_pointer, ptr, l);
	free(ptr);
	return (new_pointer);

}

/**
 * custom_memcpy - copies memeory
 *
 * @dest: a pointer to the destination string.
 * @src: a poniter to the source string.
 * @n: the number of bytes to copy as int.
 *
 * Description: copies n of memory area from src to dest;
 *
 * Return: a pointer to the memory area dest.
 */
char *custom_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _free - frees all allocated var
 * @a: pointer to all struct
 */
void _free(all_t *a)
{
	if (a->args)
		free_arg(a->args);
	if (a->env)
		f_enviro(a->env);
	if (a->ali)
		free_array(a->ali);
	if (a->envs)
		free(a->envs);
	if (a->s)
		free(a->s);
	if (a->com)
		free(a->com);
	if (a->input)
		free(a->input);
	if (a->fd)
		close(a->fd);
}
