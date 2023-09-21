#include "shell.h"


/**
 * _empty - checks if string is empty
 *
 * @s: string
 *
 * Return: 1 if empty 0 if not
 */

int _empty(char *s)
{
	int x;

	for (x = 0; s[x] && s[x] != '\n'; x++)
	{
		if (s[x] != ' ')
			return (0);
	}
	return (1);
}


/**
 * _concat -  Concatenates two strings
 * @s1: a pointer to a string
 * @s2: a pointer to a string
 *
 * Description: allocate space in memory, which
 * contains a copy of the string str.
 *
 * Return: a pointer to new string or Null if str = NULL
 * or failed to allocate memory
 */

char *_concat(char *s1, char *s2)
{
	int x, length_1 = custom_len(s1), length_2 = custom_len(s2), l = length_1 + length_2 - 1;
	char *new = malloc(sizeof(char) * (l));

	if (!new)
		return (NULL);

	for (x = 0; x < l; x++)
	{
		if (x < length_1 - 1 && length_1 != 1)
			new[x] = s1[x];
		else if (x < l - 1)
			new[x] = s2[x - length_1 + 1];
		else
			new[x] = '\0';
	}

	return (new);
}


/**
 * custom_strcmp - fucntion
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 *
 * Description: compares two strings s1 and s2
 *
 * Return: 0 if they are the same more or less on the defraces
 */

int custom_strcmp(char *s1, char *s2)
{
	int x = 0;

	while (1)
	{
		if (s1[x] == '\0' && s2[x] == '\0')
			break;
		else if (s1[x] == '\0')
			return (1);
		else if (s2[x] == '\0')
			return (1);
		else if (s1[x] != s2[x])
			return (1);
		x++;
	}
	return (0);
}



/**
 * custom_strdup -  creates a copy
 * @str: a pointer to a string
 *
 * Description: allocate space in memory, which
 * contains a copy of the string str.
 *
 * Return: a pointer to new string or Null if str = NULL
 * or failed to allocate memory
 */

char *custom_strdup(char *str)
{
	int length = custom_len(str);
	char *new = malloc(sizeof(char) * length);

	if (!length || new == NULL)
		return (NULL);

	while (length--)
	{
		new[length] = str[length];
	}

	return (new);
}



/**
 * custom_len - calculates the length of s
 * @s: apointer to string
 *
 * Return: the string of s or 0 if s = NULL
 */
int custom_len(char *s)
{
	if (!s)
		return (0);
	if (s[0])
		return (1 + custom_len(&s[1]));
	else
		return (1);
}
