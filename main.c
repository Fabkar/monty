#include "monty.h"

/**
 * main - Entry point.
 * @argc: Number of arguments.
 * @argv: aguments.
 * Return: integer.
 */
int main(int argc, char **argv)
{
	char *token = NULL;
	size_t line_size = 0;
	unsigned int line_s = 0;
	stack_t *node = NULL;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		g.fp = fopen(argv[1], "r");
		if (g.fp == NULL)
		{
			dprintf(2, "Error: Can't open file %s\n", argv[1]);
			free_listint2(node);
			exit(EXIT_FAILURE);
		}
	}
	else
		return (1);
	g.token_l = NULL;
	g.line = NULL;

	while (getline(&g.line, &line_size, g.fp) != -1)
	{
		line_s++;
		token = strtok(g.line, DELIM);
		if (token == NULL)
			continue;
		if (strcmp(token, "push") == 0)
			g.token_l = strtok(NULL, DELIM);
		match_function(token)(&node, line_s);
	}
	fclose(g.fp);
	free_listint2(node);
	free(g.line);
	return (0);
}
