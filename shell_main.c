#include "shell.h"
/**
* main - main entry point
* @ac: to get number of argument
* @av: to get argument value
* @env: to get environment value
* Return: status
*/
int main(int ac, char *av[], char **env)
{
	int count = 1;
	int stat = 0;
	(void)ac;
	
	if (ac > 1)
	{
		char err_msg[100];
		sprintf(err_msg, "%s: 0: No file or directory %s\n", av[1], av[1]);
		write(2, err_msg, strlen(err_msg));
		return (0);
	}
	stat = shell_prompt(av, count, env);
	return (stat);
}

