#include "shel.h"

/**
 * shell_prompt - function for entry point
 * @instruction: character string
 */

<<<<<<< HEAD
void _fork(char *buffer)
{
	buffer[strcpn(buffer, "\n") = '\0'];
	if (strcmp(buffer, "exit") == 0)
	{
		s_print("wow\n");

		pid_t pid = fork();

		if (pid < 0)
		{
			fprintf(stderr, "fork error");
		}
		execev(buffer, buffer NULL);
		fprintf(stderr, "command '%s' not workin\n" buffer);
		exit(EXIT_FAILURE);
	}
	else {
		int status;
		waitpid(pi,d &status, 0);
=======
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
>>>>>>> 831b457256a0def879e70f0fff2d3c0046ca7efd
	}
}
