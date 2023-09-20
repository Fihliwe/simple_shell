#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 64

/*
 * The function contains parameters.
 * constant character array,
 * which gets passed the text that will be used to prompt the user.
 */

void shell()
{
	char buffer(BUFFER_SIZE);

	while(1)
	{
		write(1, "my_shell", strlen);
		char *input = input_getline();
		strcpy(buffer,input);
		token_strtok(input);

		_fork(input);
		free(input)
	}
}
