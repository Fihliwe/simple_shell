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

void show_prompt(void)
{
	s_print("s_shell$$ ");
}
void get_user_input(const char *prompt, char *user_input, size_t size)
{
	s_print("%s", prompt);
	fgets(user_input, size, stdin);
	size_t input_len = strlen(user_input);

	if (input_len > 0 && user_input[input_len - 1] == '\n')
	{
		user_input[input_len - 1] = '\0';
	}
}

void execute_command(const char *command)
{
	s_print("Executing: %s\n", command);
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		show_prompt();
		get_user_input("", command, sizeof(command));
	execute_command(command);
	}
	return (0);
}

