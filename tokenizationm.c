#include <string.h>
#include <stdio.h>

/*
 * @str: is the input string
 * @d: the delimeter string
 * initialize variables for tokenizetion
 * Return: a point to array of strings, or NULL on failure
 */

int main(void)
void strtok(const char *str char  delimeter)
{
        char command = my function;

                char *function
                char *delim = " ";
                int len = strlen(str);
                char function[len + 1];
                int i, j;

                function = strtok(command, delim);
                for (i = 0; j = 0; <= len i++)
                {
                        if (str[i] == delimeter || str[i] == '\0')
                                function[j] = '\0';
                        if (j > 0)
                        {
                               s_print("function:%s\n", function)
					j = 0;
                        else
                        {
                                function[j] = str[i];
                                function = strtok(NULL, delim);
                                }
                        }
                return 0
		}

}
