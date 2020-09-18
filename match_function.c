#include "monty.h"
/**
 * match_function - function to execute corresponding to command line.
 * @function: function to evaluate.
 * Return: Nothing.
 */
void (*match_function(char *function))(stack_t **node, unsigned int line_s)
{
	int i = 0;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{NULL, NULL}
	};
	while (functions[i].opcode != NULL)
	{
		if (strcmp(functions[i].opcode, function) == 0)
			return (functions[i].f);
		i++;
	}
	exit(EXIT_FAILURE);
}
