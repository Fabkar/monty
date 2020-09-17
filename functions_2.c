#include "monty.h"
/**
 * digit - Function to evaluate if is a number.
 * @var: pointer to second argument of a command line.
 * Return: 1 if is a number else 0.
 */
int digit(char *var)
{
	int i = 0;

	for (; var[i] != '\0'; i++)
	{
		if (var[i] <= 48 || var[i] >= 57)
			return (0);
	}
	return (1);
}
/**
 * pint - function
 * @stack: Pointer to stack's head.
 * @line_s: line
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line_s)
{
	stack_t *head;

	head = *stack;

	if (head == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_s);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);

}
/**
 * pop - function to remove the top element from stack.
 * @stack: pointer to stack's head.
 * @line_s: line.
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_s)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_s);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}
