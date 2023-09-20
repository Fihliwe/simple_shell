#include <shell.h>
#include <stdio.h>


/*
 * main: Call the show_prompt function to display the custom prompt
 * print $$ when executing file ./shell$$
 */

void show_prompt(void)
{
	s_print("s_shell$$");
}

int main(void)
{
	show_prompt(void);

	return (0);
}
