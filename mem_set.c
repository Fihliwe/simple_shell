#include "shell.h"
/**
* mem_set - fills memory with a constant byte.
* @s: address begin to fill
* @a: value to set on memory
* @n: numbers of bytes to pointed by a
* Return: char
*/
char *mem_set(char *s, char a, unsigned int n)
{
	unsigned int count = 0;
	
	while (count < n)
	{
		*(s + count) = a;
		count++;
	}
	
	return (s);
}
