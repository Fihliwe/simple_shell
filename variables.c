#include "shell.h"

/**
 *
 *
 *
 *
 */

void _variables(char *str)
{
	char *token;
	char rest = str;
	char buff[64];
	int status;

	while (1)
	{
		token = strstr(reset, "$$");

		if (token != NULL)
		{

		}
		else 
		{
			break;
		}

		reset = token + 2;
		
		*token = '\0';
		
		sprintf("%d", buff, getpid());
		strcat(str, buffer);
		strcat(str, token + 2);
		reset = token + 2;
	}

	if (strstr(str, "$?") != NULL)
	{
		printf("exit status: %d\n", WEXITSTATUS(system(str)));
		strcpy(str, "");
	}
}


