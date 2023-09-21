#include "shell.h"

/**
 * name_file - check if the filename exist in directory.
 * @f_path: All enviroment varible PATH
 * @file_name: file name
 * Return: char
 **/

char *name_file(char *full_path, char *file_name)
{
	struct stat st;
	char *p_name;
	char *tok = NULL;
	int i = 0;

	tok = strtok(full_path, ":");
	while (tok != NULL)
	{
		p_name = malloc((_strlen(tok) + _strlen(file_name) + 2) * sizeof(char));
		if (p_name == NULL)
		{
			free(p_name);
			return (file_name);
		}
		_strcpy(p_name, tok);
		_strcat(p_name, "/");
		_strcat(p_name, file_name);
		if (stat(p_name, &st) == 0)
		{
			return (p_name);
		}
		free(p_name);
		tok = strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
