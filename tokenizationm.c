#include "string.h"
#include <stdio.h>

/*
 * @str: is the input string
 * @d: the delimeter string
 * initialize variables for tokenizetion
 * Return: a point to array of strings, or NULL on failure
 */

char *token_strtok(char *input)
{
	char *str = input;
	char *delim = " ";
	char *token;

	token = stetok(str, delim);
	while (token)
	{
		s_print("%s", token);
		token =strtok(NULL, delim);
	}
	return (0);
}
