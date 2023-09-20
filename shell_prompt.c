#include "shel.h"

/**
 * shell_prompt - function for entry point
 * @instruction: character string
 */

void shell_prompt(char *instruction)
{
	pid_t process_id;
	char *argument[];
	int stat;

	process_id = fork();
	argument = {instruction, NULL};

	if (process_id == -1)
	{
		perror("error");
	}

	else if (process_id == 0)
	{
		execve(instruction, agrument, NULL);
		perror("Execve error");
		_exit(EXIT_FAILURE);
	}

	else
	{
		waitpid(process_id, &stat, 0);

		if (WIFEXITED(stat) && WEXITSTATUS(stat) == EXIT_SUCCESS)
		{
			write(STDOUT_FILENO, "command executed\n", 30);
		}

		else
		{
			write(STDOUT_FILENO, "command failed\n", 25);
		}
	}
}
