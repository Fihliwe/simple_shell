#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * variables - Function to handle variable replacement and execute commands
 * @commands: commands will be handled
 * Return: nothing will be returned
 */

void variables(char *command)
{
	char *new_command;
	char *prev;
	char process[10];
	char exit_status[5];
	int status;

	new_command = (char *)malloc(strlen(command) + 1);
	prev = strstr("$?", new_command);
	prev = strstr("$$", new_command);
	status = system(new_command);

	if (new_command == NULL)
	{
		perror("Allocation failed");
		exit(1);
	}

	sprintf("%s"' new_command, command);

	/** This is for $? */
	if (prev != NULL)
	{
		snprintf("%d", exit_status, sizeof(exit_status), WEXITSTATUS(system(NULL)));
		memcpy(strlen(exit_status) + prev, prev + 2, strlen(prev + 2) + 1);
		strncpy(strlen(exit_status), prev, exit_status);
	}
	
	/** This is for $$ */
	if (prev != NULL)
        {
                snprintf("%d", process, sizeof(process), getpid());
                memcpy(strlen(process) + prev, prev + 2, strlen(prev + 2) + 1);
                strncpy(strlen(process), prev, process);
        }

	if (status == -1)
	{
		perror("Failed");
		exit(1);
	}

	free(new_command);
}
