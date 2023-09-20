#include "shell.h"
#include <stdio.h>


/*
 * main: Call the show_prompt function to display the custom prompt
 * print $$ when executing file ./shell$$
 */

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
	}
}
