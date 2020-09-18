#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to stack's head.
 * @line_number: line.
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_listint2(*stack);
		free(g.line);
		fclose(g.fp);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += tmp;
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to stack's head.
 * @line_number: line.
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}
