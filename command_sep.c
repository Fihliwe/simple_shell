#include "shell.h"

/**
 * command_sep -  fucntion for the command seperator.
 * @command: command will be tokenized.
 * Return: -1 and 0.
 */

int command_sep(char *command)
{
	char *argument[100];
	int argument_count;
	char *coin;
	pid_t process_id;
	int stat;

	argument_count = 0;
	coin = strtok(command, " ");
	process_id = fork();

	while (coin != NULL)
	{
		argument[argument_count++] = coin;
		coin = strtok(NULL, " ");
	}
	argument[argument_count++] = NULL;

	if (process_id == 0)
	{
		execvp(argument[0], argument);
		perror("processed");
		exit(EXIT_FAILURE);
	}

	else if (process_id > 0)
	{
		waitpid(process_id, &stat, 0);
		if (WIFEXITED(stat))
			return (WEXITSTATUS(stat));
	}

	else
	{
		perror("fork");
		return (-1);
	}

	return (0);
}
