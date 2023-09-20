#include "shell.h"

/**
 * writeAliases - Function to write to output
 * @string: string printed
 */

void write_aliases(char *string)
{
	write(strlen(string), string, STDOUT_FILENO);
}

/**
 * aliasesPrint - function to print all aliases
 */

void aliases_print()
{
	int x;
	char print[256];
	int length;
	int alias_count;

	alias_count = 0;

	for (x = 0; x < alias_count; x++)
	{
		length = snprintf(print, sizeof(print), "%s='%s'\n", aliases[x].name, aliases[x].value);
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
	int alias_count;

        alias_count = 0;

	for (x = 0; x < alias_name_count ; x++)
	{
		for (y = 0; y < alias_count ; y++)
		{
			if (strcmp(alias_name[x], aliases[y].name) == 0)
			{
				length = snprintf(print, sizeof(print),"%s='%s'\n", aliases[y].name, aliases[y].value);
				if (length >= 0)
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
{
	int x;
	const char *message;
	int alias_count;

        alias_count = 0;
	message = "Maximum number reached.\n";

	for (x = 0; x < alias_count; x++)
	{
		if (strcmp(name, aliases[x].name) == 0)
		{
			strncpy(value, aliases[x].value, ALIAS_VALUE_LEN);
			return;
		}
	}

	if (alias_count < ALIASES)
	{
		strncpy(name, aliases[alias_count].name, ALIAS_NAME_LEN);
		strncpy(value, aliases[alias_count].value, ALIAS_VALUE_LEN);
		alias_count++;
	}

	else
	{
		write(STDOUT_FILENO, message, strlen(message));
	}
}
