#include "shell.h"

/**
 * args_loop - just to make betty good
 *
 * @a: pointer to all_t
 */
void argument_loop(all_t *a)
{
	pid_t process_id;
	int x;
	char *path;

	for (x = 0; a->args[x]; x++)
	{
		if (a->args[x][0] == NULL)
			break;
		if (built_exit(a->args[x], a))
			continue;
		path = enviro_val(a->env, "PATH");
		if (a->com)
			free(a->com);
		a->com = custom_strdup(a->args[x][0]);
		a->args[x][0] = _path_(path, a->args[x][0]);
		if (l_array(a->env, &a->envs) && a->args[x][0] == NULL)
		{
			com_error(a->name, a->count, a->com);
			a->args[x][0] = malloc(1), a->status = 127;
			continue;
		}
		process_id = fork();
		if (process_id == 0 && execve(a->args[x][0], a->args[x], a->envs) == -1)
		{
			_free(a);
			exit(2);
		}
		wait(&a->status);
		a->status = a->status == 0 ? 0 : 2;
		if (!a->status && a->seq[x] == '|')
			break;
		if (a->status && a->seq[x] == '&')
			break;
	}

}
