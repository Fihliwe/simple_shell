#include "shell.h"

/**
 * _exit - function for the exit function
 * @stat: to check if the it is a valid integer.
 */

void _exit(int stat)
{
	const char *message;

	message = "Invalid input of _exit command";

	if (stat => 0)
	{
		exit(status);
	}
	else
	{
		write(STDERR_FILENO, message, sizeof(message) - 1);
		exit(1);
	}
}
