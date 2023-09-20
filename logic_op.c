#include "shell.h"

/**
 * logic_op - Function to handle && and ||.
 * @command: parameter of character.
 * Return: Nothing will be returned since its void.
 */

void logic_op(char *command)
{
	int stat;
	char *argument[64];
	char *token;
	int x;
	char success[] = "Command Success";
	char fail[50] = " Command Failed";
	pid_t process_id;

	token = strtok(command,  " ");
	x = 0;
	process_id = fork();

	if (process_id < 0)
	{
		perror("Failed");
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		while (token != NULL)
		{
			argument[x++] = token;
			token = strtok(NULL, " ");
		}
		argument[x] = NULL;

		execvp(argument[0], argument);
		perror("Command Failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(process_id, &stat, 0);

		if (WIFEXITED(stat))
		{
			if (WEXITSTATUS(stat) == 0)
			{
				write(STDOUT_FILENO, success, strlen(success));
				return (1);
			}
			else
			{
				write(STDOUT_FILENO, fail, strlen(fail));
				return (0);
			}
		}
	}
}
