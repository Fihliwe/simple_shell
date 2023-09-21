#include "shell.h"

/**
 * handle_pid_rep - replaces var with pid value
 * @arg: pointer to argument
 * @index: index of $
 * Return: the number of replaced chars
 */
int _pid_rep(char **arg, int index)
{
	int x, count;
	char *string = *arg, *num, *tmp;
	pid_t process_id = getpid();

	num = malloc(process_id / 10 + 2);
	tmp = malloc(custom_len(string) + process_id / 10);
	n_string(process_id, num);

	for (x = 0; x < index; x++)
	{
		tmp[x] = string[x];
	}
	for (count = 0; num[count]; count++)
	{
		tmp[x + count] = num[count];
	}
	index += 2;
	for (x = x + count; string[index]; x++, index++)
	{
		tmp[x] = string[index];
	}
	tmp[x] = '\0';
	*arg = tmp;
	free(num);
	free(string);

	return (count - 2);
}
