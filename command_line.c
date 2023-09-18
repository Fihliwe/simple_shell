#include <shell.h>

/*
 * print out the length of a cmd string  using a while loop;
 * use a new line char to read text
 * argc is the arguments counts
 */

int main(void)
{
        char **argv = NULL
        char *delim = " \n";
        char *cmd = NULL, *cmd_cpy = NULL, *function token = NULL;
        int argc = 0, i = 0;
        size_t n = 0;

        s_print("$$ ")
                if (getline(&n, stdin, &cmd) == -1)
                        return (-1);

        cmd_cpy = strdup(cmd);
        function token = strtok(cmd, delim);

        while (function token)
        {
                function token = strtok(NULL, delim);
                argc++;s_print("%d\n", argc);
        argv = malloc(sizeof(char * ) *argc);

        return(0);
	}
}
