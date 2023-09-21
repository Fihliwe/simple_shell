#include "shell.h"


/**
 * interactive_mode - handles the input from terminal
 *
 * @a: struct conatins all var needed to pass
 *
 */

void inter_mode(all_t *a)
{
	int length, size = 0;

	for (a->count = 1; a->count; a->count++, size = 0)
	{
		if (a->s)
			free(a->s);
		a->s = NULL;
		write(STDOUT_FILENO, "$ ", 2);
		length = _getline_(&a->s, &size, a->fd);
		if (length == 0 || length == EOF)
		{
			if (length == 0)
				write(a->fd, "\n", 1);
			_free(a);
			exit(a->status);
		}
		if (_empty(a->s))
			continue;
		free_arg(a->args);
		a->args = _strtok(a->s, a->seq);
		argument_loop(a);
	}
}


/**
 * non_interactive_mode - handles files and echo, cat
 *
 * @a: struct conatins all var needed to pass
 */
void non_inter_mode(all_t *a)
{
	int length, size = 0, i;

	for (a->count = 1; a->count; a->count++)
	{
		if (a->input)
			free(a->input);
		a->input = NULL;
		size = 0;
		length = _getline_(&a->input, &size, a->fd);
		if (length == 0 || length == EOF)
		{
			_free(a);
			exit(a->status);
		}
		if (_empty(a->input))
			continue;
		i = 0;
		while (a->input[i])
		{
			if (a->s)
				free(a->s);
			a->s = _strtok1(a->input, &i, '\n');
			if (a->args)
				free_arg(a->args);
			a->args = NULL;
			a->args = _strtok(a->s, a->seq);
			argument_loop(a);
		}
	}
}

