#include <shell.h>

/*
 * file description for stdout uses the write function to creat s_print
 * general code to Print Integer in C language
 */

void s_print(const char *print function)
{
        write(STDOUT_FILENO, print function, strlen(print function));
}
