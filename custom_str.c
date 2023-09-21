#include "shell.h"

/**
 * *_strcpy - copies the string pointed to by src to the buffer pointed to dest
 * @dest: char dest
 * @src: char src
 * Return: dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	char a;

	for (i = 0; src[i] != '\0'; i++)
	{
		a = src[i];
		dest[i] = a;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string.
 * @s: pointer to String
 * Return: Nothing
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcat - concatinate two strings.
 * @dest: accepts destination string.
 * @src: accepts source string.
 * Return: pointer to the destination string.
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}

	dest[i + j] = '\0';

	return (dest);
}

/**
 * _strdup - this functions copy a string.
 * @str: the string to copy
 * Description: this function copy a string)?
 * section header: the header of this function is hsh.
 * Return: this is a void function no return
 **/

char *_strdup(char *str)
{
	int j, l;
	char *s;

	if (!str)
	{
		return (NULL);
	}

	l = _strlen(str) + 1;

	s = mem_alloc(l, sizeof(char));
	if (!s)
	{
		return (NULL);
	}

	for (j = 0; j < l; j++)
	{
		s[j] = str[j];
	}
	return (s);
}

/**
 * _strcmp - compare two strings.
 * @s1: accepts destination string.
 * @s2: accepts source string.
 * Return: pointer to the destination string.
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] != '\0' && s2[x] != '\0'; x++)
	{
		if (s1[x] != s2[x])
		{
			return (s1[x] - s2[x]);
		}
	}
	return (0);
}

/**
 *_strncmp -  function that compares two strings.
 *@s1: string one
 *@s2: string two
 *@n: number of characters
 * Return: diference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0, j = 0;

	while (n && s1[i] && (s1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
	{
	return (0);
	}
	else
	{
	return (s1[i] - s2[j]);
	}
}
