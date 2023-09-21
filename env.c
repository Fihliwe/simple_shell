#include "shell.h"

/**
 * env_command - This function create a child process and executes
 * @av: Pointer to an array of strings 
 * @counter: Executions
 * @enviro: Enviroment
 * Return: void
 **/
int env_command(char *av[], int counter_exec, char **env)
{
	char *path = NULL, *file = NULL, error[100];
	int status = 0, found = 0, e_status = 0;
	pid_t child_pid;
	struct stat st;

	if (stat(av[1], &st) == 0)
		found = 1, file = av[1];
	else
	{
		path = _setenv("PATH", env), file = name_file(path, av[1]);
		if (file != NULL)
			found = 1;
		free(path); }
	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(file, (av + 1), env)) == -1)
			{
				sprintf(error, "%s: %d: %s: not found\n", av[0], counter_exec, av[1]);
				write(2, error, _strlen(error));
			}
		}
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status))
		{
			e_status = WEXITSTATUS(status);
			return (e_status);
		}
	}
	else
	{
		sprintf(error, "%s: %d: %s: not found\n", av[0], counter_exec, av[1]);
		write(2, error, _strlen(error));
		return (127);
	}
	return (0);
}
