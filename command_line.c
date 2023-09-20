#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * print out the length of a cmd string  using a while loop;
 * use a new line char to read text
 * argc is the arguments counts
 */


int main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL;
	char **argv = NULL;
	char *delim = " \n";
	char *token = NULL;
	int argc = 0;
	size_t n = 0;

	s_print("$$ ");

	if (getline(&cmd, &n, stdin) == -1)
	{
		perror("getline");
		return (-1);
	}
	cmd_cpy = strdup(cmd);
	token = strtok(cmd_cpy, delim);
	while (token)
	{
		argv = realloc(argv, (argc + 1) * sizeof(char *));
		if (!argv)
		{
			perror("realloc");
			exit(1);
		}
		argv[argc] = strdup(token);
		token = strtok(NULL, delim);
		argc++;
	}
	for (int i = 0; i < argc; i++)
	{
		s_print("Arg %d: %s\n", i, argv[i]);
	}
	for (int i = 0; i < argc; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(cmd);
	free(cmd_cpy);
	return (0);
}
