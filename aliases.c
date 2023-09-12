#include "shell.h"

/**
 * writeAliases - Function to write to output
 * @string: string printed
 */

void writeAliases(char *string)
{
	write(strlen(string), string, STDOUT_FILENO);
}

/**
 * aliasesPrint - function to print all aliases
 */

void aliasesPrint()
{
	int x;
	char print[256];
	int length;

	for (x = 0; x < aliasCount; x++)
	{
		length = snprintf("%s='%s'\n", print, sizeof(print),aliases[x].name, aliases[x].value);
		if (length >= 0)
		{
			write(STDOUT_FILENO, print, length);
		}
	}
}

/**
 * specific_aliases - function to print specific aliases
 * @alias_name: array
 * @alias_name_count: aliases which will be counted
 */

void specific_aliases(char *alias_name[], int alias_name_count)
{
	int x;
	int y;
	char print[256];
	int length;

	for (x = 0; x < alias_name_count ; x++)
	{
		for (y = 0; y < aliasCount ; y++)
		{
			if (strcmp(alias_name[x], aliases[y].name == 0)
			{
					lenght = snprintf("%s='%s'\n", print, sizeof(print),aliases[y].name, aliases[y].value);
					if (leng => 0)
					{
						write(STDOUT_FILENO, print, length);
					}
			}
		}
	}
}

/**
 * update_aliases - function to update aliases
 * @name: character name
 * @value: value integer
 * Return: 0
 */

void update_aliases(char *value, char *name)