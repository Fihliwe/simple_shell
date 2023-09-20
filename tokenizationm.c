#include "string.h"
#include <stdio.h>

/*
 * @str: is the input string
 * @d: the delimeter string
 * initialize variables for tokenizetion
 * Return: a point to array of strings, or NULL on failure
 */

void custom_strtok(const char *str, char delimiter)
{
	int len = strlen(str);
	char function[len + 1];
	int j = 0;

	for (int i = 0; i <= len; i++)
	{
		if (str[i] == delimiter || str[i] == '\0')
		{
			function[j] = '\0';
			if (j > 0)
			{
				s_print("function: %s\n", function);
			}
			j = 0;
		} else
		{
			function[j] = str[i];
			j++;
		}
	}
}

int main(void)
{
	const char *command = "my shell function with arguments";
	char delimiter = ' ';

	custom_strtok(command, delimiter);

	return (0);
}
