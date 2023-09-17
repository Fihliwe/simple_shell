#include "shell.h"

/**
 * change_dir - function for cd command.
 * @change: character for directory.
 * Return: 1 for failed 0 for pass.
 */

int change_dir(const char *change)
{
	char current_directory[CD_LENGTH];
	char *home_directory;

	home_directory = getenv("home directory");

	if (change == NULL || strcmp(change, "") == 0)
	{
		change = home_directory;
	}

	else if (strcmp(change, "-") == 0)
	{
		change = getenv("old working directory");
	}

	if (chdir(change) == 0)
	{
		if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		{
			setenv("old working directory", getenv("previous working directory"), 1);
			setenv("previous working directory", current_directory, 1);
			write(STDOUT_FILENO, "working directory: ", 19);
			write(STDOUT_FILENO, current_directory, strlen(current_directory));
			write(STDOUT_FILENO, "\n", 1);
		}

		else
		{
			perror("getcwd");
			return (1);
		}
	}
	else
	{
		perror("chdir");
		return (1);
	}
	return (0);
}
