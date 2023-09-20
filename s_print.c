#include "shell.h"
#include <unistd.h>
#include <string.h>

/*
 * file description for stdout uses the write function to creat s_print
 * general code to Print Integer in C language
 * return 0
 */


char s_print(char *argv)
{
	size_t count = strlen(argv);
	write(1, argv, count);
	return argv;
}
