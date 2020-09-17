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
		{NULL, NULL}
	};
	while (i < 4)
	{
		if (strcmp(functions[i].opcode, function) == 0)
			return (functions[i].f);
		i++;
	}
	return (NULL);
}
