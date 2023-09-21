#include "shell.h"

/**
* mem_alloc - function that allocates memory for an array
* @x: amount to values
* @size: number of bytes
*
* Return: Void 
*/
void *mem_alloc(unsigned int memn, int size)
{
	void *pointer = NULL;
	
	if (memn == 0 || size == 0)
	{
		return (NULL);
	}
	
	pointer = malloc(memn * size);
	
	if (pointer == NULL)
	{
		return (NULL);
	}
	
	mem_set(pointer, 0, size * memn);
	return (pointer);
}
