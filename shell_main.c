#include "shell.h"

int main(void)
{
	char input[INPUT_LENGTH];
	const char *dir = input + 3;
	int result = change_dir(dir);
	
	while (1)
	{
		show_prompt();
		get_user_input("", input, sizeof(input));
		
		if (strcmp(input, "exit") == 0)
		{
			_exit(0);
		}
		
		else if (strncmp(input, "cd ", 3) == 0)
		{
			if (result != 0)
			{
				fprintf(stderr, "cd: Failed to change directory\n");
			}
			continue;
		}
		
		else if (strncmp(input, "alias ", 6) == 0)
		{
			/** add the alias command */
			continue;
		}
		
		if (result == -1)
		{
			fprintf(stderr, "Command execution failed\n");
		}
	}

	return (0);
}

