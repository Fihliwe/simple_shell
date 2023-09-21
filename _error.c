#include "shell.h"


/**
 * file_err - prints files errors
 *
 * @a: pointer to all struct
 * @file: file name as string
 */
void f_error(all_t *a, char *file)
{
	char s[1024], *err = "Can't open ";
	int length;

	custom_memcpy(s, a->name, custom_len(a->name) - 1);
	custom_memcpy(&s[custom_len(a->name) - 1], ": ", 2);
	custom_memcpy(&s[custom_len(a->name) + 1], "0", 1);
	length = custom_len(a->name) + 2 + 3;
	custom_memcpy(&s[length - 3], ": ", 2);
	custom_memcpy(&s[length - 1], err, custom_len(err) - 1);
	custom_memcpy(&s[length + custom_len(err) - 2], file, custom_len(file) - 1);
	length = length + custom_len(err) + custom_len(file) - 3;
	custom_memcpy(&s[length], "\n", 2);
	write(STDERR_FILENO, s, custom_len(s) - 1);
	fflush(stderr);
	a->fd = 0;
	_free(a);
}



/**
 * comand_err - prints commands errors
 *
 * @name: name of the file
 * @n: exe count
 * @com: name of the command
 */
void com_error(char *name, int n, char *com)
{
	char *string, *tmp1 = malloc(10), *tmp2;


	string = _concat(name, ": ");
	n_string(n, tmp1);
	tmp2 = _concat(string, tmp1);
	free(tmp1);
	free(string);
	tmp1 = _concat(tmp2, ": ");
	free(tmp2);
	string = _concat(tmp1, com);
	free(tmp1);

	if (custom_len(com) > 255)
		tmp1 = _concat(string, ": File name too long\n");
	else
		tmp1 = _concat(string, ": not found\n");

	write(STDERR_FILENO, tmp1, custom_len(tmp1) - 1);
	free(tmp1);
	free(string);
}
