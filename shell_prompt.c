#include "shell.h"

/**
* shell_prompt - reads the command line a through getline and determine
* the mode either interactive or non-interactive from the command line.
* @av: Pointer to arrays of string
* @counter_exe: command execution counter.
* @env: Enviroment variable.
* Return: status value.
**/

<<<<<<< HEAD
int shell_prompt(char *av[], int counter_exe, char **env)
=======
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
>>>>>>> 4b7795b8f9da43b6750581b6a46872b481ea8b7e
{
	int interactive = isatty(STDIN_FILENO), p_status = 0, i = 0, read = 0;
	size_t length = 0;
	char *line = NULL, *arguments[32], *tok = NULL;
	
	while (1)
	{
		{
			if (interactive)
			{
				write(STDIN_FILENO, "$ ", 3);
			}
		}
		
		read = getline(&line, &length, stdin);
		
		if (read == EOF)
		{
			if (interactive)
			{
				write(STDIN_FILENO, "\n", 1);
				free(line);
			}
			break;
		}
		
		else if (_strncmp(line, "exit\n", 4) == 0)
		{
			free(line);
			break;
		}
		
		else
		{
			if (_strncmp(line, "env\n", 3) == 0)
			{
				_getenv(env);
			}
				
			
			else if (read > 1)
			{
				tok = strtok(line, " \t\r\n\v\f"), arguments[0] = av[0];
				for (i = 1; i < 32 && tok != NULL; i++)
				{
					arguments[i] = tok, tok = strtok(NULL, " \t\r\n\v\f");
					arguments[i] = NULL;
					
					if (arguments[1])
					{
						p_status = env_command(arguments, counter_exe, env);
					}
				}
				counter_exe++;
			}
		}
>>>>>>> 831b457256a0def879e70f0fff2d3c0046ca7efd
	}
	return (p_status);
}
