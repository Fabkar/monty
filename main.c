#include "monty.h"

/**
 * main - Entry point.
 * @argc: Number of arguments.
 * @argv: aguments.
 * Return: integer.
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL, *token = NULL, **strings = NULL;
	size_t line_size = 0;
	unsigned int line_s = 0;
	stack_t *node = NULL;

	if(argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
		return (1);
	strings = malloc(sizeof(char *) * 100);
	if (!strings)
		exit(EXIT_FAILURE);
	g = malloc(sizeof(global_t));
	if (!g)
		exit(EXIT_FAILURE);
	g->token_l = NULL;

	while (getline(&line, &line_size, fp) != -1)
	{
		line_s++;
		token = strtok(line, " \t\n");
		if (strcmp(token, "push") == 0)
			g->token_l = strtok(NULL, " \t\n");
		match_function(token)(&node, line_s);
	}
	free(strings);
	free_listint2(&node);
	free(line);
	free(g);
	return (0);
}
