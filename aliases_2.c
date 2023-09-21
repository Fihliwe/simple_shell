#include "shell.h"


/**
 * build_ali - builds alias
 * @ali: alias full value
 * @val: only the value after =
 * Return: pointer to the value
 */
char *b_alias(char *ali, char *val)
{
	int x;
	char *string;

	for (x = 0; ali[x] != '='; x++)
	{
	}
	ali[x + 1] = '\0';

	string = _concat(ali, val);

	return (string);
}

/**
 * print_alias - prints alias format
 * @ali: string alias
 */
void p_alias(char *ali)
{
	int x;
	char *tmp = malloc(custom_len(ali) + 2);

	for (x = 0; ali[x] != '='; x++)
	{
		tmp[x] = ali[x];
	}
	tmp[x++] = '=';
	tmp[x] = '\'';
	while (ali[x])
	{
		tmp[x + 1] = ali[x];
		x++;
	}
	tmp[++x] = '\'';
	tmp[++x] = '\n';
	write(STDOUT_FILENO, tmp, x + 1);
	free(tmp);
}
