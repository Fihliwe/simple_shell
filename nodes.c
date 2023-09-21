#include "shell.h"


/**
 * add_node - add node
 * @head: head of node
 * @env_value: string
 * Return: 1 success 0 otherwise
 */
int a_node(node **head, char *env_value)
{
	node *tmp;

	tmp = malloc(sizeof(node));
	if (tmp == NULL)
	{
		write(STDOUT_FILENO, "filed add_node\n", 15);
		return (0);
	}
	tmp->next = *head;
	tmp->env = strdup(env_value);
	*head = tmp;
	return (1);
}

/**
 * get_node - pointer to node
 * @env: env list head
 * @name: name of the env
 * Return: pointer to the value
 */
node *g_node(node *env, char *name)
{
	node *tmp = env;

	while (tmp)
	{
		if (enviro_comp(tmp->env, name))
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
