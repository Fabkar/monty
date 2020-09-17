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
		{NULL, NULL}
	};
	while (i < 2)
	{
		if (strcmp(functions[i].opcode, function) == 0)
			return (functions[i].f);
		i++;
	}
	return (NULL);
}
