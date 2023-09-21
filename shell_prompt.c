#include "shell.h"

/**
* shell_prompt - reads the command line a through getline and determine
* the mode either interactive or non-interactive from the command line.
* @av: Pointer to arrays of string
* @counter_exe: command execution counter.
* @env: Enviroment variable.
* Return: status value.
**/

int shell_prompt(char *av[], int counter_exe, char **env)
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
	}
	return (p_status);
}
