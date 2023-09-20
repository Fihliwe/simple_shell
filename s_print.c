#include "shell.h"
#include <unistd.h>
#include <string.h>

/*
 * file description for stdout uses the write function to creat s_print
 * general code to Print Integer in C language
 * return 0
 */


int main(void)
{
	const char *string = "hello shell!";
	size_t len = strlen(string);

	write(1, string, len);

	return (0);
}
